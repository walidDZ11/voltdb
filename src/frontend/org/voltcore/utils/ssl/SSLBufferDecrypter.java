/* This file is part of VoltDB.
 * Copyright (C) 2008-2016 VoltDB Inc.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with VoltDB.  If not, see <http://www.gnu.org/licenses/>.
 */

package org.voltcore.utils.ssl;

import org.voltdb.common.Constants;

import javax.net.ssl.SSLEngine;
import javax.net.ssl.SSLEngineResult;
import javax.net.ssl.SSLException;
import java.io.IOException;
import java.nio.ByteBuffer;
import java.util.ArrayList;
import java.util.List;

public class SSLBufferDecrypter {

    private final SSLEngine m_sslEngine;
    private ByteBuffer m_partialMessage;
    private ByteBuffer m_partialLength;
    private ByteBuffer m_partialBuffer;

    public SSLBufferDecrypter(SSLEngine sslEngine) {
        this.m_sslEngine = sslEngine;
    }

    public List<ByteBuffer> decryptBuffer(ByteBuffer buffer) throws IOException {

        ByteBuffer dstBuffer;
        ByteBuffer srcBuffer;
        if (m_partialBuffer != null) {
            dstBuffer = ByteBuffer.allocate(m_partialBuffer.remaining() + buffer.remaining() + 128);
            srcBuffer = ByteBuffer.allocate(m_partialBuffer.remaining() + buffer.remaining());
            srcBuffer.put(m_partialBuffer);
            srcBuffer.put(buffer);
            srcBuffer.flip();
            m_partialBuffer = null;
        } else {
            dstBuffer = ByteBuffer.allocate(buffer.remaining() + 128);
            srcBuffer = buffer;
        }


        List<ByteBuffer> messages = new ArrayList<>();
        while (srcBuffer.hasRemaining()) {
            // might have a partial buffer from last time.  Partial buffer holds bytes
            // that were read but could not yet be decrypted.
            List<ByteBuffer> chunks = unwrapBuffer(srcBuffer, dstBuffer);
            for (ByteBuffer chunk : chunks) {
                while (chunk.hasRemaining()) {
                    if (m_partialLength != null) {
                        if (chunk.remaining() >= (4 - m_partialLength.remaining())) {
                            // write the rest of the length into the buffer, flip it
                            int oldLimit = chunk.limit();
                            chunk.limit(chunk.position() + m_partialLength.remaining());
                            m_partialLength.put(chunk.slice());
                            chunk.position(chunk.limit());
                            chunk.limit(oldLimit);

                            m_partialLength.flip();
                            int messageLength = m_partialLength.getInt();
                            m_partialLength = null;

                            if (chunk.remaining() >= messageLength) {
                                oldLimit = chunk.limit();
                                chunk.limit(chunk.position() + messageLength);
                                ByteBuffer message = chunk.slice();
                                messages.add(message);
                                chunk.position(chunk.limit());
                                chunk.limit(oldLimit);
                            } else {
                                m_partialMessage = ByteBuffer.allocate(messageLength);
                                m_partialMessage.put(chunk);
                            }
                        } else {
                            // net enough remaining in chunk to finish length.
                            m_partialLength.put(chunk);
                        }
                    } else if (m_partialMessage != null) {
                        if (chunk.remaining() >= m_partialMessage.remaining()) {
                            int oldLimit = chunk.limit();
                            chunk.limit(chunk.position() + m_partialMessage.remaining());
                            m_partialMessage.put(chunk.slice());
                            m_partialMessage.flip();
                            messages.add(m_partialMessage);
                            m_partialMessage = null;
                            chunk.position(chunk.limit());
                            chunk.limit(oldLimit);
                        } else {
                            m_partialMessage.put(chunk);
                        }
                    } else {
                        // at a message boundary.
                        if (chunk.remaining() >= 4) {
                            int messageLength = chunk.getInt();
                            if (chunk.remaining() >= messageLength) {
                                int oldLimit = chunk.limit();
                                chunk.limit(chunk.position() + messageLength);
                                ByteBuffer message = chunk.slice();
                                messages.add(message);
                                chunk.position(chunk.limit());
                                chunk.limit(oldLimit);
                            } else {
                                m_partialMessage = ByteBuffer.allocate(messageLength);
                                m_partialMessage.put(chunk.slice());
                                chunk.position(chunk.limit());
                            }
                        } else {
                            m_partialLength = ByteBuffer.allocate(4);
                            m_partialLength.put(chunk.slice());
                            chunk.position(chunk.limit());
                        }
                    }
                }
            }
        }
        return messages;
    }

    private List<ByteBuffer> unwrapBuffer(ByteBuffer src, ByteBuffer dst) throws IOException {
        List<ByteBuffer> chunks = new ArrayList<ByteBuffer>();
        while (src.hasRemaining()) {
            ByteBuffer srcSlice = src.slice();
            ByteBuffer dstSlice = dst.slice();
            SSLEngineResult result = m_sslEngine.unwrap(srcSlice, dstSlice);
            switch (result.getStatus()) {
                case OK:
                    dst.limit(dst.position() + result.bytesProduced());
                    chunks.add(dst.slice());
                    dst.position(dst.limit());
                    dst.limit(dst.capacity());
                    src.position(src.position() + result.bytesConsumed());
                    break;
                case BUFFER_OVERFLOW:
                    m_partialBuffer = src.slice();
                    src.position(src.limit());
                    return chunks;
                case BUFFER_UNDERFLOW:
                    m_partialBuffer = src.slice();
                    src.position(src.limit());
                    return chunks;
                case CLOSED:
                    throw new SSLException("SSL engine is closed on ssl unwrapBuffer of buffer.");
            }
        }
        return chunks;
    }
}
