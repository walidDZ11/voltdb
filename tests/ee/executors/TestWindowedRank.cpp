/* This file is part of VoltDB.
 * Copyright (C) 2008-2017 VoltDB Inc.
 *
 * This file contains original code and/or modifications of original code.
 * Any modifications made by VoltDB Inc. are licensed under the following
 * terms and conditions:
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */
/**
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements. See the NOTICE file distributed with this
 * work for additional information regarding copyright ownership. The ASF
 * licenses this file to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
 * License for the specific language governing permissions and limitations under
 * the License.
 */
/******************************************************************************************
 *
 * NOTA BENE: This file is automagically generated from the source class named
 *                org.voltdb.planner.EEPlanTestGenerator.
 *            Please do not edit it unless you abandon all hope of regenerating it.
 *
 ******************************************************************************************/
#include "harness.h"

#include "catalog/cluster.h"
#include "catalog/table.h"
#include "plannodes/abstractplannode.h"
#include "storage/persistenttable.h"
#include "storage/temptable.h"
#include "storage/tableutil.h"
#include "test_utils/plan_testing_config.h"
#include "test_utils/LoadTableFrom.hpp"
#include "test_utils/plan_testing_baseclass.h"


namespace {
extern TestConfig allTests[];
};

class TestWindowedRank : public PlanTestingBaseClass<EngineTestTopend> {
public:
    /*
     * This constructor lets us set the global random seed for the
     * random number generator.  It would be better to have a seed
     * just for this test.  But that is not easily done.
     */
    TestWindowedRank(uint32_t randomSeed = (unsigned int)time(NULL)) {
        initialize(m_testDB, randomSeed);
    }

    ~TestWindowedRank() { }
protected:
    static DBConfig         m_testDB;
};

/*
 * All the test cases are here.
 */
TEST_F(TestWindowedRank, test_rank) {
    static int testIndex = 0;
    executeTest(allTests[testIndex]);
}
TEST_F(TestWindowedRank, test_dense_rank) {
    static int testIndex = 1;
    executeTest(allTests[testIndex]);
}


namespace {
/*
 * These are the names of all the columns.
 */
const char *T_ColumnNames[] = {
    "A",
    "B",
    "C",
};
const char *rank_output_ColumnNames[] = {
    "A",
    "B",
    "C",
    "D",
};
const char *rank_dense_output_ColumnNames[] = {
    "A",
    "B",
    "C",
    "D",
};


/*
 * These are the types of all the columns.
 */
const voltdb::ValueType T_Types[] = {
    voltdb::VALUE_TYPE_INTEGER,
    voltdb::VALUE_TYPE_INTEGER,
    voltdb::VALUE_TYPE_INTEGER,
};
const voltdb::ValueType rank_output_Types[] = {
    voltdb::VALUE_TYPE_INTEGER,
    voltdb::VALUE_TYPE_INTEGER,
    voltdb::VALUE_TYPE_INTEGER,
    voltdb::VALUE_TYPE_INTEGER,
};
const voltdb::ValueType rank_dense_output_Types[] = {
    voltdb::VALUE_TYPE_INTEGER,
    voltdb::VALUE_TYPE_INTEGER,
    voltdb::VALUE_TYPE_INTEGER,
    voltdb::VALUE_TYPE_INTEGER,
};


/*
 * These are the sizes of all the column data.
 */
const int32_t T_Sizes[] = {
    4,
    4,
    4,
};
const int32_t rank_output_Sizes[] = {
    4,
    4,
    4,
    4,
};
const int32_t rank_dense_output_Sizes[] = {
    4,
    4,
    4,
    4,
};


/*
 * These are the strings in each populated columns.
 * The data will either be integers or indices into this table.
 */
int32_t num_T_strings = 0;
const char *T_Strings[] = {
};
int32_t num_rank_output_strings = 0;
const char *rank_output_Strings[] = {
};
int32_t num_rank_dense_output_strings = 0;
const char *rank_dense_output_Strings[] = {
};


/*
 * This is the data in all columns.
 */
const int NUM_TABLE_ROWS_T = 15;
const int NUM_TABLE_COLS_T = 3;
const int TData[NUM_TABLE_ROWS_T * NUM_TABLE_COLS_T] = {
      1,  1,101,
      1,  1,102,
      1,  2,201,
      1,  2,202,
      1,  3,203,
      2,  1,1101,
      2,  1,1102,
      2,  2,1201,
      2,  2,1202,
      2,  3,1203,
     20,  1,2101,
     20,  1,2102,
     20,  2,2201,
     20,  2,2202,
     20,  3,2203,
};

const int NUM_TABLE_ROWS_RANK_OUTPUT = 15;
const int NUM_TABLE_COLS_RANK_OUTPUT = 4;
const int rank_outputData[NUM_TABLE_ROWS_RANK_OUTPUT * NUM_TABLE_COLS_RANK_OUTPUT] = {
      1,  1,101,  1,
      1,  1,102,  1,
      1,  2,201,  3,
      1,  2,202,  3,
      1,  3,203,  5,
      2,  1,1101,  1,
      2,  1,1102,  1,
      2,  2,1201,  3,
      2,  2,1202,  3,
      2,  3,1203,  5,
     20,  1,2101,  1,
     20,  1,2102,  1,
     20,  2,2201,  3,
     20,  2,2202,  3,
     20,  3,2203,  5,
};

const int NUM_TABLE_ROWS_RANK_DENSE_OUTPUT = 15;
const int NUM_TABLE_COLS_RANK_DENSE_OUTPUT = 4;
const int rank_dense_outputData[NUM_TABLE_ROWS_RANK_DENSE_OUTPUT * NUM_TABLE_COLS_RANK_DENSE_OUTPUT] = {
      1,  1,101,  1,
      1,  1,102,  1,
      1,  2,201,  2,
      1,  2,202,  2,
      1,  3,203,  3,
      2,  1,1101,  1,
      2,  1,1102,  1,
      2,  2,1201,  2,
      2,  2,1202,  2,
      2,  3,1203,  3,
     20,  1,2101,  1,
     20,  1,2102,  1,
     20,  2,2201,  2,
     20,  2,2202,  2,
     20,  3,2203,  3,
};



/*
 * These are the names of all the columns.
 */
/*
 * These knit together all the bits of data which form a table.
 */
const TableConfig TConfig = {
    "T",
    T_ColumnNames,
    T_Types,
    T_Sizes,
    NUM_TABLE_ROWS_T,
    NUM_TABLE_COLS_T,
    TData,
    T_Strings,
    num_T_strings
};
const TableConfig rank_outputConfig = {
    "rank_output",
    rank_output_ColumnNames,
    rank_output_Types,
    rank_output_Sizes,
    NUM_TABLE_ROWS_RANK_OUTPUT,
    NUM_TABLE_COLS_RANK_OUTPUT,
    rank_outputData,
    rank_output_Strings,
    num_rank_output_strings
};
const TableConfig rank_dense_outputConfig = {
    "rank_dense_output",
    rank_dense_output_ColumnNames,
    rank_dense_output_Types,
    rank_dense_output_Sizes,
    NUM_TABLE_ROWS_RANK_DENSE_OUTPUT,
    NUM_TABLE_COLS_RANK_DENSE_OUTPUT,
    rank_dense_outputData,
    rank_dense_output_Strings,
    num_rank_dense_output_strings
};


/*
 * This holds all the persistent tables.
 */
const TableConfig *allTables[] = {
    &TConfig,
    &rank_outputConfig,
    &rank_dense_outputConfig,
};


TestConfig allTests[2] = {
    {
        // SQL Statement
        "select A, B, C, rank() over (partition by A order by B) as R from T ORDER BY A, B, C, R;",
        // Plan String
        "{\n"
        "    \"EXECUTE_LIST\": [\n"
        "        6,\n"
        "        5,\n"
        "        4,\n"
        "        3,\n"
        "        2,\n"
        "        1\n"
        "    ],\n"
        "    \"PLAN_NODES\": [\n"
        "        {\n"
        "            \"CHILDREN_IDS\": [2],\n"
        "            \"ID\": 1,\n"
        "            \"PLAN_NODE_TYPE\": \"SEND\"\n"
        "        },\n"
        "        {\n"
        "            \"CHILDREN_IDS\": [3],\n"
        "            \"ID\": 2,\n"
        "            \"OUTPUT_SCHEMA\": [\n"
        "                {\n"
        "                    \"COLUMN_NAME\": \"A\",\n"
        "                    \"EXPRESSION\": {\n"
        "                        \"COLUMN_IDX\": 1,\n"
        "                        \"TYPE\": 32,\n"
        "                        \"VALUE_TYPE\": 5\n"
        "                    }\n"
        "                },\n"
        "                {\n"
        "                    \"COLUMN_NAME\": \"B\",\n"
        "                    \"EXPRESSION\": {\n"
        "                        \"COLUMN_IDX\": 2,\n"
        "                        \"TYPE\": 32,\n"
        "                        \"VALUE_TYPE\": 5\n"
        "                    }\n"
        "                },\n"
        "                {\n"
        "                    \"COLUMN_NAME\": \"C\",\n"
        "                    \"EXPRESSION\": {\n"
        "                        \"COLUMN_IDX\": 3,\n"
        "                        \"TYPE\": 32,\n"
        "                        \"VALUE_TYPE\": 5\n"
        "                    }\n"
        "                },\n"
        "                {\n"
        "                    \"COLUMN_NAME\": \"R\",\n"
        "                    \"EXPRESSION\": {\n"
        "                        \"COLUMN_IDX\": 0,\n"
        "                        \"TYPE\": 32,\n"
        "                        \"VALUE_TYPE\": 6\n"
        "                    }\n"
        "                }\n"
        "            ],\n"
        "            \"PLAN_NODE_TYPE\": \"PROJECTION\"\n"
        "        },\n"
        "        {\n"
        "            \"CHILDREN_IDS\": [4],\n"
        "            \"ID\": 3,\n"
        "            \"PLAN_NODE_TYPE\": \"ORDERBY\",\n"
        "            \"SORT_COLUMNS\": [\n"
        "                {\n"
        "                    \"SORT_DIRECTION\": \"ASC\",\n"
        "                    \"SORT_EXPRESSION\": {\n"
        "                        \"COLUMN_IDX\": 1,\n"
        "                        \"TYPE\": 32,\n"
        "                        \"VALUE_TYPE\": 5\n"
        "                    }\n"
        "                },\n"
        "                {\n"
        "                    \"SORT_DIRECTION\": \"ASC\",\n"
        "                    \"SORT_EXPRESSION\": {\n"
        "                        \"COLUMN_IDX\": 2,\n"
        "                        \"TYPE\": 32,\n"
        "                        \"VALUE_TYPE\": 5\n"
        "                    }\n"
        "                },\n"
        "                {\n"
        "                    \"SORT_DIRECTION\": \"ASC\",\n"
        "                    \"SORT_EXPRESSION\": {\n"
        "                        \"COLUMN_IDX\": 3,\n"
        "                        \"TYPE\": 32,\n"
        "                        \"VALUE_TYPE\": 5\n"
        "                    }\n"
        "                },\n"
        "                {\n"
        "                    \"SORT_DIRECTION\": \"ASC\",\n"
        "                    \"SORT_EXPRESSION\": {\n"
        "                        \"COLUMN_IDX\": 0,\n"
        "                        \"TYPE\": 32,\n"
        "                        \"VALUE_TYPE\": 6\n"
        "                    }\n"
        "                }\n"
        "            ]\n"
        "        },\n"
        "        {\n"
        "            \"AGGREGATE_COLUMNS\": [{\n"
        "                \"AGGREGATE_EXPRESSIONS\": [],\n"
        "                \"AGGREGATE_OUTPUT_COLUMN\": 0,\n"
        "                \"AGGREGATE_TYPE\": \"AGGREGATE_WINDOWED_RANK\"\n"
        "            }],\n"
        "            \"CHILDREN_IDS\": [5],\n"
        "            \"ID\": 4,\n"
        "            \"OUTPUT_SCHEMA\": [\n"
        "                {\n"
        "                    \"COLUMN_NAME\": \"R\",\n"
        "                    \"EXPRESSION\": {\n"
        "                        \"COLUMN_IDX\": 0,\n"
        "                        \"TYPE\": 32,\n"
        "                        \"VALUE_TYPE\": 6\n"
        "                    }\n"
        "                },\n"
        "                {\n"
        "                    \"COLUMN_NAME\": \"A\",\n"
        "                    \"EXPRESSION\": {\n"
        "                        \"COLUMN_IDX\": 0,\n"
        "                        \"TYPE\": 32,\n"
        "                        \"VALUE_TYPE\": 5\n"
        "                    }\n"
        "                },\n"
        "                {\n"
        "                    \"COLUMN_NAME\": \"B\",\n"
        "                    \"EXPRESSION\": {\n"
        "                        \"COLUMN_IDX\": 1,\n"
        "                        \"TYPE\": 32,\n"
        "                        \"VALUE_TYPE\": 5\n"
        "                    }\n"
        "                },\n"
        "                {\n"
        "                    \"COLUMN_NAME\": \"C\",\n"
        "                    \"EXPRESSION\": {\n"
        "                        \"COLUMN_IDX\": 2,\n"
        "                        \"TYPE\": 32,\n"
        "                        \"VALUE_TYPE\": 5\n"
        "                    }\n"
        "                }\n"
        "            ],\n"
        "            \"PARTITIONBY_EXPRESSIONS\": [{\n"
        "                \"COLUMN_IDX\": 0,\n"
        "                \"TYPE\": 32,\n"
        "                \"VALUE_TYPE\": 5\n"
        "            }],\n"
        "            \"PLAN_NODE_TYPE\": \"WINDOWFUNCTION\",\n"
        "            \"SORT_COLUMNS\": [{\"SORT_EXPRESSION\": {\n"
        "                \"COLUMN_IDX\": 1,\n"
        "                \"TYPE\": 32,\n"
        "                \"VALUE_TYPE\": 5\n"
        "            }}]\n"
        "        },\n"
        "        {\n"
        "            \"CHILDREN_IDS\": [6],\n"
        "            \"ID\": 5,\n"
        "            \"PLAN_NODE_TYPE\": \"ORDERBY\",\n"
        "            \"SORT_COLUMNS\": [\n"
        "                {\n"
        "                    \"SORT_DIRECTION\": \"ASC\",\n"
        "                    \"SORT_EXPRESSION\": {\n"
        "                        \"COLUMN_IDX\": 0,\n"
        "                        \"TYPE\": 32,\n"
        "                        \"VALUE_TYPE\": 5\n"
        "                    }\n"
        "                },\n"
        "                {\n"
        "                    \"SORT_DIRECTION\": \"ASC\",\n"
        "                    \"SORT_EXPRESSION\": {\n"
        "                        \"COLUMN_IDX\": 1,\n"
        "                        \"TYPE\": 32,\n"
        "                        \"VALUE_TYPE\": 5\n"
        "                    }\n"
        "                }\n"
        "            ]\n"
        "        },\n"
        "        {\n"
        "            \"ID\": 6,\n"
        "            \"INLINE_NODES\": [{\n"
        "                \"ID\": 7,\n"
        "                \"OUTPUT_SCHEMA\": [\n"
        "                    {\n"
        "                        \"COLUMN_NAME\": \"A\",\n"
        "                        \"EXPRESSION\": {\n"
        "                            \"COLUMN_IDX\": 0,\n"
        "                            \"TYPE\": 32,\n"
        "                            \"VALUE_TYPE\": 5\n"
        "                        }\n"
        "                    },\n"
        "                    {\n"
        "                        \"COLUMN_NAME\": \"B\",\n"
        "                        \"EXPRESSION\": {\n"
        "                            \"COLUMN_IDX\": 1,\n"
        "                            \"TYPE\": 32,\n"
        "                            \"VALUE_TYPE\": 5\n"
        "                        }\n"
        "                    },\n"
        "                    {\n"
        "                        \"COLUMN_NAME\": \"C\",\n"
        "                        \"EXPRESSION\": {\n"
        "                            \"COLUMN_IDX\": 2,\n"
        "                            \"TYPE\": 32,\n"
        "                            \"VALUE_TYPE\": 5\n"
        "                        }\n"
        "                    }\n"
        "                ],\n"
        "                \"PLAN_NODE_TYPE\": \"PROJECTION\"\n"
        "            }],\n"
        "            \"PLAN_NODE_TYPE\": \"SEQSCAN\",\n"
        "            \"TARGET_TABLE_ALIAS\": \"T\",\n"
        "            \"TARGET_TABLE_NAME\": \"T\"\n"
        "        }\n"
        "    ]\n"
        "}",
        &rank_outputConfig
    },
    {
        // SQL Statement
        "select A, B, C, dense_rank() over (partition by A order by B) as R from T ORDER BY A, B, C, R;",
        // Plan String
        "{\n"
        "    \"EXECUTE_LIST\": [\n"
        "        6,\n"
        "        5,\n"
        "        4,\n"
        "        3,\n"
        "        2,\n"
        "        1\n"
        "    ],\n"
        "    \"PLAN_NODES\": [\n"
        "        {\n"
        "            \"CHILDREN_IDS\": [2],\n"
        "            \"ID\": 1,\n"
        "            \"PLAN_NODE_TYPE\": \"SEND\"\n"
        "        },\n"
        "        {\n"
        "            \"CHILDREN_IDS\": [3],\n"
        "            \"ID\": 2,\n"
        "            \"OUTPUT_SCHEMA\": [\n"
        "                {\n"
        "                    \"COLUMN_NAME\": \"A\",\n"
        "                    \"EXPRESSION\": {\n"
        "                        \"COLUMN_IDX\": 1,\n"
        "                        \"TYPE\": 32,\n"
        "                        \"VALUE_TYPE\": 5\n"
        "                    }\n"
        "                },\n"
        "                {\n"
        "                    \"COLUMN_NAME\": \"B\",\n"
        "                    \"EXPRESSION\": {\n"
        "                        \"COLUMN_IDX\": 2,\n"
        "                        \"TYPE\": 32,\n"
        "                        \"VALUE_TYPE\": 5\n"
        "                    }\n"
        "                },\n"
        "                {\n"
        "                    \"COLUMN_NAME\": \"C\",\n"
        "                    \"EXPRESSION\": {\n"
        "                        \"COLUMN_IDX\": 3,\n"
        "                        \"TYPE\": 32,\n"
        "                        \"VALUE_TYPE\": 5\n"
        "                    }\n"
        "                },\n"
        "                {\n"
        "                    \"COLUMN_NAME\": \"R\",\n"
        "                    \"EXPRESSION\": {\n"
        "                        \"COLUMN_IDX\": 0,\n"
        "                        \"TYPE\": 32,\n"
        "                        \"VALUE_TYPE\": 6\n"
        "                    }\n"
        "                }\n"
        "            ],\n"
        "            \"PLAN_NODE_TYPE\": \"PROJECTION\"\n"
        "        },\n"
        "        {\n"
        "            \"CHILDREN_IDS\": [4],\n"
        "            \"ID\": 3,\n"
        "            \"PLAN_NODE_TYPE\": \"ORDERBY\",\n"
        "            \"SORT_COLUMNS\": [\n"
        "                {\n"
        "                    \"SORT_DIRECTION\": \"ASC\",\n"
        "                    \"SORT_EXPRESSION\": {\n"
        "                        \"COLUMN_IDX\": 1,\n"
        "                        \"TYPE\": 32,\n"
        "                        \"VALUE_TYPE\": 5\n"
        "                    }\n"
        "                },\n"
        "                {\n"
        "                    \"SORT_DIRECTION\": \"ASC\",\n"
        "                    \"SORT_EXPRESSION\": {\n"
        "                        \"COLUMN_IDX\": 2,\n"
        "                        \"TYPE\": 32,\n"
        "                        \"VALUE_TYPE\": 5\n"
        "                    }\n"
        "                },\n"
        "                {\n"
        "                    \"SORT_DIRECTION\": \"ASC\",\n"
        "                    \"SORT_EXPRESSION\": {\n"
        "                        \"COLUMN_IDX\": 3,\n"
        "                        \"TYPE\": 32,\n"
        "                        \"VALUE_TYPE\": 5\n"
        "                    }\n"
        "                },\n"
        "                {\n"
        "                    \"SORT_DIRECTION\": \"ASC\",\n"
        "                    \"SORT_EXPRESSION\": {\n"
        "                        \"COLUMN_IDX\": 0,\n"
        "                        \"TYPE\": 32,\n"
        "                        \"VALUE_TYPE\": 6\n"
        "                    }\n"
        "                }\n"
        "            ]\n"
        "        },\n"
        "        {\n"
        "            \"AGGREGATE_COLUMNS\": [{\n"
        "                \"AGGREGATE_EXPRESSIONS\": [],\n"
        "                \"AGGREGATE_OUTPUT_COLUMN\": 0,\n"
        "                \"AGGREGATE_TYPE\": \"AGGREGATE_WINDOWED_DENSE_RANK\"\n"
        "            }],\n"
        "            \"CHILDREN_IDS\": [5],\n"
        "            \"ID\": 4,\n"
        "            \"OUTPUT_SCHEMA\": [\n"
        "                {\n"
        "                    \"COLUMN_NAME\": \"R\",\n"
        "                    \"EXPRESSION\": {\n"
        "                        \"COLUMN_IDX\": 0,\n"
        "                        \"TYPE\": 32,\n"
        "                        \"VALUE_TYPE\": 6\n"
        "                    }\n"
        "                },\n"
        "                {\n"
        "                    \"COLUMN_NAME\": \"A\",\n"
        "                    \"EXPRESSION\": {\n"
        "                        \"COLUMN_IDX\": 0,\n"
        "                        \"TYPE\": 32,\n"
        "                        \"VALUE_TYPE\": 5\n"
        "                    }\n"
        "                },\n"
        "                {\n"
        "                    \"COLUMN_NAME\": \"B\",\n"
        "                    \"EXPRESSION\": {\n"
        "                        \"COLUMN_IDX\": 1,\n"
        "                        \"TYPE\": 32,\n"
        "                        \"VALUE_TYPE\": 5\n"
        "                    }\n"
        "                },\n"
        "                {\n"
        "                    \"COLUMN_NAME\": \"C\",\n"
        "                    \"EXPRESSION\": {\n"
        "                        \"COLUMN_IDX\": 2,\n"
        "                        \"TYPE\": 32,\n"
        "                        \"VALUE_TYPE\": 5\n"
        "                    }\n"
        "                }\n"
        "            ],\n"
        "            \"PARTITIONBY_EXPRESSIONS\": [{\n"
        "                \"COLUMN_IDX\": 0,\n"
        "                \"TYPE\": 32,\n"
        "                \"VALUE_TYPE\": 5\n"
        "            }],\n"
        "            \"PLAN_NODE_TYPE\": \"WINDOWFUNCTION\",\n"
        "            \"SORT_COLUMNS\": [{\"SORT_EXPRESSION\": {\n"
        "                \"COLUMN_IDX\": 1,\n"
        "                \"TYPE\": 32,\n"
        "                \"VALUE_TYPE\": 5\n"
        "            }}]\n"
        "        },\n"
        "        {\n"
        "            \"CHILDREN_IDS\": [6],\n"
        "            \"ID\": 5,\n"
        "            \"PLAN_NODE_TYPE\": \"ORDERBY\",\n"
        "            \"SORT_COLUMNS\": [\n"
        "                {\n"
        "                    \"SORT_DIRECTION\": \"ASC\",\n"
        "                    \"SORT_EXPRESSION\": {\n"
        "                        \"COLUMN_IDX\": 0,\n"
        "                        \"TYPE\": 32,\n"
        "                        \"VALUE_TYPE\": 5\n"
        "                    }\n"
        "                },\n"
        "                {\n"
        "                    \"SORT_DIRECTION\": \"ASC\",\n"
        "                    \"SORT_EXPRESSION\": {\n"
        "                        \"COLUMN_IDX\": 1,\n"
        "                        \"TYPE\": 32,\n"
        "                        \"VALUE_TYPE\": 5\n"
        "                    }\n"
        "                }\n"
        "            ]\n"
        "        },\n"
        "        {\n"
        "            \"ID\": 6,\n"
        "            \"INLINE_NODES\": [{\n"
        "                \"ID\": 7,\n"
        "                \"OUTPUT_SCHEMA\": [\n"
        "                    {\n"
        "                        \"COLUMN_NAME\": \"A\",\n"
        "                        \"EXPRESSION\": {\n"
        "                            \"COLUMN_IDX\": 0,\n"
        "                            \"TYPE\": 32,\n"
        "                            \"VALUE_TYPE\": 5\n"
        "                        }\n"
        "                    },\n"
        "                    {\n"
        "                        \"COLUMN_NAME\": \"B\",\n"
        "                        \"EXPRESSION\": {\n"
        "                            \"COLUMN_IDX\": 1,\n"
        "                            \"TYPE\": 32,\n"
        "                            \"VALUE_TYPE\": 5\n"
        "                        }\n"
        "                    },\n"
        "                    {\n"
        "                        \"COLUMN_NAME\": \"C\",\n"
        "                        \"EXPRESSION\": {\n"
        "                            \"COLUMN_IDX\": 2,\n"
        "                            \"TYPE\": 32,\n"
        "                            \"VALUE_TYPE\": 5\n"
        "                        }\n"
        "                    }\n"
        "                ],\n"
        "                \"PLAN_NODE_TYPE\": \"PROJECTION\"\n"
        "            }],\n"
        "            \"PLAN_NODE_TYPE\": \"SEQSCAN\",\n"
        "            \"TARGET_TABLE_ALIAS\": \"T\",\n"
        "            \"TARGET_TABLE_NAME\": \"T\"\n"
        "        }\n"
        "    ]\n"
        "}",
        &rank_dense_outputConfig
    },
};

}

DBConfig TestWindowedRank::m_testDB =

{
    //
    // DDL.
    //
    "drop table T if exists;\n"
    "drop table AAA if exists;\n"
    "drop table BBB if exists;\n"
    "drop table R1 if exists;\n"
    "\n"
    "CREATE TABLE T (\n"
    "  A INTEGER,\n"
    "  B INTEGER,\n"
    "  C INTEGER\n"
    ");\n"
    "\n"
    "CREATE TABLE R1 (\n"
    "  ID INTEGER NOT NULL,\n"
    "  TINY INTEGER NOT NULL,\n"
    "  BIG INTEGER NOT NULL,\n"
    "  PRIMARY KEY (ID)\n"
    ");\n"
    "\n"
    "create table AAA (\n"
    "  A integer,\n"
    "  B integer,\n"
    "  C integer\n"
    " );\n"
    " \n"
    " create table BBB (\n"
    "  A integer,\n"
    "  B integer,\n"
    "  C integer\n"
    " );\n"
    " \n"
    "create table CCC (\n"
    "  id integer,\n"
    "  name varchar(32),\n"
    "  data varchar(1024)\n"
    ");\n"
    " \n"
    "create table XXX (\n"
    "  id integer primary key not null,\n"
    "  name varchar(32),\n"
    "  data varchar(1024)\n"
    ");\n"
    "",
    //
    // Catalog String
    //
    "add / clusters cluster\n"
    "set /clusters#cluster localepoch 0\n"
    "set $PREV securityEnabled false\n"
    "set $PREV httpdportno 0\n"
    "set $PREV jsonapi false\n"
    "set $PREV networkpartition false\n"
    "set $PREV heartbeatTimeout 0\n"
    "set $PREV useddlschema false\n"
    "set $PREV drConsumerEnabled false\n"
    "set $PREV drProducerEnabled false\n"
    "set $PREV drRole \"\"\n"
    "set $PREV drClusterId 0\n"
    "set $PREV drProducerPort 0\n"
    "set $PREV drMasterHost \"\"\n"
    "set $PREV drFlushInterval 0\n"
    "add /clusters#cluster databases database\n"
    "set /clusters#cluster/databases#database schema \"eJy9UsuOw0AIu+/XzICBcE2a/P8nrRml+1CabXroCk1GGoxtII4Q36JJC3h38cVNmkGapzu/FpNnaCBU5w9/CEeveK1EKl4qMdEzDagJDN2A4Z52BAv2TmTiaWWTJ7EWCgEzkWXPyGlGD5km+bfk8PklmsCRAiu2ssZXY9VylyOmkHm9gqrJcV1XoD9ib3QuQ2cmPsvvcJp7e65cgXnnAuzxsn9OlUtZC+nBxfya6klGD5n2XHj/Zf5fWCu+hUmAMwFfWXcbDE4ucfWpbplUVTjeOw5DqT/AdW0qemUVNlU8MdaisT5pivRBUp/5nsPqFoVfw8i3vLGFTyRq52Q=\"\n"
    "set $PREV isActiveActiveDRed false\n"
    "set $PREV securityprovider \"\"\n"
    "add /clusters#cluster/databases#database groups administrator\n"
    "set /clusters#cluster/databases#database/groups#administrator admin true\n"
    "set $PREV defaultproc true\n"
    "set $PREV defaultprocread true\n"
    "set $PREV sql true\n"
    "set $PREV sqlread true\n"
    "set $PREV allproc true\n"
    "add /clusters#cluster/databases#database groups user\n"
    "set /clusters#cluster/databases#database/groups#user admin false\n"
    "set $PREV defaultproc true\n"
    "set $PREV defaultprocread true\n"
    "set $PREV sql true\n"
    "set $PREV sqlread true\n"
    "set $PREV allproc true\n"
    "add /clusters#cluster/databases#database tables AAA\n"
    "set /clusters#cluster/databases#database/tables#AAA isreplicated true\n"
    "set $PREV partitioncolumn null\n"
    "set $PREV estimatedtuplecount 0\n"
    "set $PREV materializer null\n"
    "set $PREV signature \"AAA|iii\"\n"
    "set $PREV tuplelimit 2147483647\n"
    "set $PREV isDRed false\n"
    "add /clusters#cluster/databases#database/tables#AAA columns A\n"
    "set /clusters#cluster/databases#database/tables#AAA/columns#A index 0\n"
    "set $PREV type 5\n"
    "set $PREV size 4\n"
    "set $PREV nullable true\n"
    "set $PREV name \"A\"\n"
    "set $PREV defaultvalue null\n"
    "set $PREV defaulttype 0\n"
    "set $PREV aggregatetype 0\n"
    "set $PREV matviewsource null\n"
    "set $PREV matview null\n"
    "set $PREV inbytes false\n"
    "add /clusters#cluster/databases#database/tables#AAA columns B\n"
    "set /clusters#cluster/databases#database/tables#AAA/columns#B index 1\n"
    "set $PREV type 5\n"
    "set $PREV size 4\n"
    "set $PREV nullable true\n"
    "set $PREV name \"B\"\n"
    "set $PREV defaultvalue null\n"
    "set $PREV defaulttype 0\n"
    "set $PREV aggregatetype 0\n"
    "set $PREV matviewsource null\n"
    "set $PREV matview null\n"
    "set $PREV inbytes false\n"
    "add /clusters#cluster/databases#database/tables#AAA columns C\n"
    "set /clusters#cluster/databases#database/tables#AAA/columns#C index 2\n"
    "set $PREV type 5\n"
    "set $PREV size 4\n"
    "set $PREV nullable true\n"
    "set $PREV name \"C\"\n"
    "set $PREV defaultvalue null\n"
    "set $PREV defaulttype 0\n"
    "set $PREV aggregatetype 0\n"
    "set $PREV matviewsource null\n"
    "set $PREV matview null\n"
    "set $PREV inbytes false\n"
    "add /clusters#cluster/databases#database tables BBB\n"
    "set /clusters#cluster/databases#database/tables#BBB isreplicated true\n"
    "set $PREV partitioncolumn null\n"
    "set $PREV estimatedtuplecount 0\n"
    "set $PREV materializer null\n"
    "set $PREV signature \"BBB|iii\"\n"
    "set $PREV tuplelimit 2147483647\n"
    "set $PREV isDRed false\n"
    "add /clusters#cluster/databases#database/tables#BBB columns A\n"
    "set /clusters#cluster/databases#database/tables#BBB/columns#A index 0\n"
    "set $PREV type 5\n"
    "set $PREV size 4\n"
    "set $PREV nullable true\n"
    "set $PREV name \"A\"\n"
    "set $PREV defaultvalue null\n"
    "set $PREV defaulttype 0\n"
    "set $PREV aggregatetype 0\n"
    "set $PREV matviewsource null\n"
    "set $PREV matview null\n"
    "set $PREV inbytes false\n"
    "add /clusters#cluster/databases#database/tables#BBB columns B\n"
    "set /clusters#cluster/databases#database/tables#BBB/columns#B index 1\n"
    "set $PREV type 5\n"
    "set $PREV size 4\n"
    "set $PREV nullable true\n"
    "set $PREV name \"B\"\n"
    "set $PREV defaultvalue null\n"
    "set $PREV defaulttype 0\n"
    "set $PREV aggregatetype 0\n"
    "set $PREV matviewsource null\n"
    "set $PREV matview null\n"
    "set $PREV inbytes false\n"
    "add /clusters#cluster/databases#database/tables#BBB columns C\n"
    "set /clusters#cluster/databases#database/tables#BBB/columns#C index 2\n"
    "set $PREV type 5\n"
    "set $PREV size 4\n"
    "set $PREV nullable true\n"
    "set $PREV name \"C\"\n"
    "set $PREV defaultvalue null\n"
    "set $PREV defaulttype 0\n"
    "set $PREV aggregatetype 0\n"
    "set $PREV matviewsource null\n"
    "set $PREV matview null\n"
    "set $PREV inbytes false\n"
    "add /clusters#cluster/databases#database tables CCC\n"
    "set /clusters#cluster/databases#database/tables#CCC isreplicated true\n"
    "set $PREV partitioncolumn null\n"
    "set $PREV estimatedtuplecount 0\n"
    "set $PREV materializer null\n"
    "set $PREV signature \"CCC|ivv\"\n"
    "set $PREV tuplelimit 2147483647\n"
    "set $PREV isDRed false\n"
    "add /clusters#cluster/databases#database/tables#CCC columns DATA\n"
    "set /clusters#cluster/databases#database/tables#CCC/columns#DATA index 2\n"
    "set $PREV type 9\n"
    "set $PREV size 1024\n"
    "set $PREV nullable true\n"
    "set $PREV name \"DATA\"\n"
    "set $PREV defaultvalue null\n"
    "set $PREV defaulttype 0\n"
    "set $PREV aggregatetype 0\n"
    "set $PREV matviewsource null\n"
    "set $PREV matview null\n"
    "set $PREV inbytes false\n"
    "add /clusters#cluster/databases#database/tables#CCC columns ID\n"
    "set /clusters#cluster/databases#database/tables#CCC/columns#ID index 0\n"
    "set $PREV type 5\n"
    "set $PREV size 4\n"
    "set $PREV nullable true\n"
    "set $PREV name \"ID\"\n"
    "set $PREV defaultvalue null\n"
    "set $PREV defaulttype 0\n"
    "set $PREV aggregatetype 0\n"
    "set $PREV matviewsource null\n"
    "set $PREV matview null\n"
    "set $PREV inbytes false\n"
    "add /clusters#cluster/databases#database/tables#CCC columns NAME\n"
    "set /clusters#cluster/databases#database/tables#CCC/columns#NAME index 1\n"
    "set $PREV type 9\n"
    "set $PREV size 32\n"
    "set $PREV nullable true\n"
    "set $PREV name \"NAME\"\n"
    "set $PREV defaultvalue null\n"
    "set $PREV defaulttype 0\n"
    "set $PREV aggregatetype 0\n"
    "set $PREV matviewsource null\n"
    "set $PREV matview null\n"
    "set $PREV inbytes false\n"
    "add /clusters#cluster/databases#database tables R1\n"
    "set /clusters#cluster/databases#database/tables#R1 isreplicated true\n"
    "set $PREV partitioncolumn null\n"
    "set $PREV estimatedtuplecount 0\n"
    "set $PREV materializer null\n"
    "set $PREV signature \"R1|iii\"\n"
    "set $PREV tuplelimit 2147483647\n"
    "set $PREV isDRed false\n"
    "add /clusters#cluster/databases#database/tables#R1 columns BIG\n"
    "set /clusters#cluster/databases#database/tables#R1/columns#BIG index 2\n"
    "set $PREV type 5\n"
    "set $PREV size 4\n"
    "set $PREV nullable false\n"
    "set $PREV name \"BIG\"\n"
    "set $PREV defaultvalue null\n"
    "set $PREV defaulttype 0\n"
    "set $PREV aggregatetype 0\n"
    "set $PREV matviewsource null\n"
    "set $PREV matview null\n"
    "set $PREV inbytes false\n"
    "add /clusters#cluster/databases#database/tables#R1 columns ID\n"
    "set /clusters#cluster/databases#database/tables#R1/columns#ID index 0\n"
    "set $PREV type 5\n"
    "set $PREV size 4\n"
    "set $PREV nullable false\n"
    "set $PREV name \"ID\"\n"
    "set $PREV defaultvalue null\n"
    "set $PREV defaulttype 0\n"
    "set $PREV aggregatetype 0\n"
    "set $PREV matviewsource null\n"
    "set $PREV matview null\n"
    "set $PREV inbytes false\n"
    "add /clusters#cluster/databases#database/tables#R1 columns TINY\n"
    "set /clusters#cluster/databases#database/tables#R1/columns#TINY index 1\n"
    "set $PREV type 5\n"
    "set $PREV size 4\n"
    "set $PREV nullable false\n"
    "set $PREV name \"TINY\"\n"
    "set $PREV defaultvalue null\n"
    "set $PREV defaulttype 0\n"
    "set $PREV aggregatetype 0\n"
    "set $PREV matviewsource null\n"
    "set $PREV matview null\n"
    "set $PREV inbytes false\n"
    "add /clusters#cluster/databases#database/tables#R1 indexes VOLTDB_AUTOGEN_IDX_PK_R1_ID\n"
    "set /clusters#cluster/databases#database/tables#R1/indexes#VOLTDB_AUTOGEN_IDX_PK_R1_ID unique true\n"
    "set $PREV assumeUnique false\n"
    "set $PREV countable true\n"
    "set $PREV type 1\n"
    "set $PREV expressionsjson \"\"\n"
    "set $PREV predicatejson \"\"\n"
    "add /clusters#cluster/databases#database/tables#R1/indexes#VOLTDB_AUTOGEN_IDX_PK_R1_ID columns ID\n"
    "set /clusters#cluster/databases#database/tables#R1/indexes#VOLTDB_AUTOGEN_IDX_PK_R1_ID/columns#ID index 0\n"
    "set $PREV column /clusters#cluster/databases#database/tables#R1/columns#ID\n"
    "add /clusters#cluster/databases#database/tables#R1 constraints VOLTDB_AUTOGEN_IDX_PK_R1_ID\n"
    "set /clusters#cluster/databases#database/tables#R1/constraints#VOLTDB_AUTOGEN_IDX_PK_R1_ID type 4\n"
    "set $PREV oncommit \"\"\n"
    "set $PREV index /clusters#cluster/databases#database/tables#R1/indexes#VOLTDB_AUTOGEN_IDX_PK_R1_ID\n"
    "set $PREV foreignkeytable null\n"
    "add /clusters#cluster/databases#database tables T\n"
    "set /clusters#cluster/databases#database/tables#T isreplicated true\n"
    "set $PREV partitioncolumn null\n"
    "set $PREV estimatedtuplecount 0\n"
    "set $PREV materializer null\n"
    "set $PREV signature \"T|iii\"\n"
    "set $PREV tuplelimit 2147483647\n"
    "set $PREV isDRed false\n"
    "add /clusters#cluster/databases#database/tables#T columns A\n"
    "set /clusters#cluster/databases#database/tables#T/columns#A index 0\n"
    "set $PREV type 5\n"
    "set $PREV size 4\n"
    "set $PREV nullable true\n"
    "set $PREV name \"A\"\n"
    "set $PREV defaultvalue null\n"
    "set $PREV defaulttype 0\n"
    "set $PREV aggregatetype 0\n"
    "set $PREV matviewsource null\n"
    "set $PREV matview null\n"
    "set $PREV inbytes false\n"
    "add /clusters#cluster/databases#database/tables#T columns B\n"
    "set /clusters#cluster/databases#database/tables#T/columns#B index 1\n"
    "set $PREV type 5\n"
    "set $PREV size 4\n"
    "set $PREV nullable true\n"
    "set $PREV name \"B\"\n"
    "set $PREV defaultvalue null\n"
    "set $PREV defaulttype 0\n"
    "set $PREV aggregatetype 0\n"
    "set $PREV matviewsource null\n"
    "set $PREV matview null\n"
    "set $PREV inbytes false\n"
    "add /clusters#cluster/databases#database/tables#T columns C\n"
    "set /clusters#cluster/databases#database/tables#T/columns#C index 2\n"
    "set $PREV type 5\n"
    "set $PREV size 4\n"
    "set $PREV nullable true\n"
    "set $PREV name \"C\"\n"
    "set $PREV defaultvalue null\n"
    "set $PREV defaulttype 0\n"
    "set $PREV aggregatetype 0\n"
    "set $PREV matviewsource null\n"
    "set $PREV matview null\n"
    "set $PREV inbytes false\n"
    "add /clusters#cluster/databases#database tables XXX\n"
    "set /clusters#cluster/databases#database/tables#XXX isreplicated true\n"
    "set $PREV partitioncolumn null\n"
    "set $PREV estimatedtuplecount 0\n"
    "set $PREV materializer null\n"
    "set $PREV signature \"XXX|ivv\"\n"
    "set $PREV tuplelimit 2147483647\n"
    "set $PREV isDRed false\n"
    "add /clusters#cluster/databases#database/tables#XXX columns DATA\n"
    "set /clusters#cluster/databases#database/tables#XXX/columns#DATA index 2\n"
    "set $PREV type 9\n"
    "set $PREV size 1024\n"
    "set $PREV nullable true\n"
    "set $PREV name \"DATA\"\n"
    "set $PREV defaultvalue null\n"
    "set $PREV defaulttype 0\n"
    "set $PREV aggregatetype 0\n"
    "set $PREV matviewsource null\n"
    "set $PREV matview null\n"
    "set $PREV inbytes false\n"
    "add /clusters#cluster/databases#database/tables#XXX columns ID\n"
    "set /clusters#cluster/databases#database/tables#XXX/columns#ID index 0\n"
    "set $PREV type 5\n"
    "set $PREV size 4\n"
    "set $PREV nullable false\n"
    "set $PREV name \"ID\"\n"
    "set $PREV defaultvalue null\n"
    "set $PREV defaulttype 0\n"
    "set $PREV aggregatetype 0\n"
    "set $PREV matviewsource null\n"
    "set $PREV matview null\n"
    "set $PREV inbytes false\n"
    "add /clusters#cluster/databases#database/tables#XXX columns NAME\n"
    "set /clusters#cluster/databases#database/tables#XXX/columns#NAME index 1\n"
    "set $PREV type 9\n"
    "set $PREV size 32\n"
    "set $PREV nullable true\n"
    "set $PREV name \"NAME\"\n"
    "set $PREV defaultvalue null\n"
    "set $PREV defaulttype 0\n"
    "set $PREV aggregatetype 0\n"
    "set $PREV matviewsource null\n"
    "set $PREV matview null\n"
    "set $PREV inbytes false\n"
    "add /clusters#cluster/databases#database/tables#XXX indexes VOLTDB_AUTOGEN_IDX_PK_XXX_ID\n"
    "set /clusters#cluster/databases#database/tables#XXX/indexes#VOLTDB_AUTOGEN_IDX_PK_XXX_ID unique true\n"
    "set $PREV assumeUnique false\n"
    "set $PREV countable true\n"
    "set $PREV type 1\n"
    "set $PREV expressionsjson \"\"\n"
    "set $PREV predicatejson \"\"\n"
    "add /clusters#cluster/databases#database/tables#XXX/indexes#VOLTDB_AUTOGEN_IDX_PK_XXX_ID columns ID\n"
    "set /clusters#cluster/databases#database/tables#XXX/indexes#VOLTDB_AUTOGEN_IDX_PK_XXX_ID/columns#ID index 0\n"
    "set $PREV column /clusters#cluster/databases#database/tables#XXX/columns#ID\n"
    "add /clusters#cluster/databases#database/tables#XXX constraints VOLTDB_AUTOGEN_IDX_PK_XXX_ID\n"
    "set /clusters#cluster/databases#database/tables#XXX/constraints#VOLTDB_AUTOGEN_IDX_PK_XXX_ID type 4\n"
    "set $PREV oncommit \"\"\n"
    "set $PREV index /clusters#cluster/databases#database/tables#XXX/indexes#VOLTDB_AUTOGEN_IDX_PK_XXX_ID\n"
    "set $PREV foreignkeytable null\n"
    "add /clusters#cluster/databases#database procedures testplanseegenerator\n"
    "set /clusters#cluster/databases#database/procedures#testplanseegenerator classname \"\"\n"
    "set $PREV readonly false\n"
    "set $PREV singlepartition false\n"
    "set $PREV everysite false\n"
    "set $PREV systemproc false\n"
    "set $PREV defaultproc false\n"
    "set $PREV hasjava false\n"
    "set $PREV hasseqscans false\n"
    "set $PREV language \"\"\n"
    "set $PREV partitiontable null\n"
    "set $PREV partitioncolumn null\n"
    "set $PREV partitionparameter 0\n"
    "set $PREV allowedInShutdown false\n"
    "add /clusters#cluster/databases#database/procedures#testplanseegenerator statements stmt-0\n"
    "set /clusters#cluster/databases#database/procedures#testplanseegenerator/statements#stmt-0 sqltext \"select A, B from AAA order by A, B;\"\n"
    "set $PREV querytype 2\n"
    "set $PREV readonly true\n"
    "set $PREV singlepartition true\n"
    "set $PREV replicatedtabledml false\n"
    "set $PREV iscontentdeterministic false\n"
    "set $PREV isorderdeterministic false\n"
    "set $PREV nondeterminismdetail \"\"\n"
    "set $PREV cost 0\n"
    "set $PREV seqscancount 0\n"
    "set $PREV explainplan \"\"\n"
    "set $PREV tablesread \"\"\n"
    "set $PREV tablesupdated \"\"\n"
    "set $PREV indexesused \"\"\n"
    "set $PREV cachekeyprefix \"\"\n"
    "add /clusters#cluster/databases#database/procedures#testplanseegenerator statements stmt-1\n"
    "set /clusters#cluster/databases#database/procedures#testplanseegenerator/statements#stmt-1 sqltext \"select AAA.A, AAA.B, BBB.C from AAA join BBB on AAA.C = BBB.C order by AAA.A, AAA.B, AAA.C;\"\n"
    "set $PREV querytype 2\n"
    "set $PREV readonly true\n"
    "set $PREV singlepartition true\n"
    "set $PREV replicatedtabledml false\n"
    "set $PREV iscontentdeterministic false\n"
    "set $PREV isorderdeterministic false\n"
    "set $PREV nondeterminismdetail \"\"\n"
    "set $PREV cost 0\n"
    "set $PREV seqscancount 0\n"
    "set $PREV explainplan \"\"\n"
    "set $PREV tablesread \"\"\n"
    "set $PREV tablesupdated \"\"\n"
    "set $PREV indexesused \"\"\n"
    "set $PREV cachekeyprefix \"\"\n"
    "add /clusters#cluster/databases#database/procedures#testplanseegenerator statements stmt-10\n"
    "set /clusters#cluster/databases#database/procedures#testplanseegenerator/statements#stmt-10 sqltext \"select A, B, max(-1 * abs(5-C)) over (partition by A order by B) as R from T ORDER BY A, B, R;\"\n"
    "set $PREV querytype 2\n"
    "set $PREV readonly true\n"
    "set $PREV singlepartition true\n"
    "set $PREV replicatedtabledml false\n"
    "set $PREV iscontentdeterministic false\n"
    "set $PREV isorderdeterministic false\n"
    "set $PREV nondeterminismdetail \"\"\n"
    "set $PREV cost 0\n"
    "set $PREV seqscancount 0\n"
    "set $PREV explainplan \"\"\n"
    "set $PREV tablesread \"\"\n"
    "set $PREV tablesupdated \"\"\n"
    "set $PREV indexesused \"\"\n"
    "set $PREV cachekeyprefix \"\"\n"
    "add /clusters#cluster/databases#database/procedures#testplanseegenerator statements stmt-11\n"
    "set /clusters#cluster/databases#database/procedures#testplanseegenerator/statements#stmt-11 sqltext \"select A, B, sum(B+C) over (partition by A order by B) as R from T ORDER BY A, B, R;\"\n"
    "set $PREV querytype 2\n"
    "set $PREV readonly true\n"
    "set $PREV singlepartition true\n"
    "set $PREV replicatedtabledml false\n"
    "set $PREV iscontentdeterministic false\n"
    "set $PREV isorderdeterministic false\n"
    "set $PREV nondeterminismdetail \"\"\n"
    "set $PREV cost 0\n"
    "set $PREV seqscancount 0\n"
    "set $PREV explainplan \"\"\n"
    "set $PREV tablesread \"\"\n"
    "set $PREV tablesupdated \"\"\n"
    "set $PREV indexesused \"\"\n"
    "set $PREV cachekeyprefix \"\"\n"
    "add /clusters#cluster/databases#database/procedures#testplanseegenerator statements stmt-2\n"
    "set /clusters#cluster/databases#database/procedures#testplanseegenerator/statements#stmt-2 sqltext \"select * from CCC;\"\n"
    "set $PREV querytype 2\n"
    "set $PREV readonly true\n"
    "set $PREV singlepartition true\n"
    "set $PREV replicatedtabledml false\n"
    "set $PREV iscontentdeterministic false\n"
    "set $PREV isorderdeterministic false\n"
    "set $PREV nondeterminismdetail \"\"\n"
    "set $PREV cost 0\n"
    "set $PREV seqscancount 0\n"
    "set $PREV explainplan \"\"\n"
    "set $PREV tablesread \"\"\n"
    "set $PREV tablesupdated \"\"\n"
    "set $PREV indexesused \"\"\n"
    "set $PREV cachekeyprefix \"\"\n"
    "add /clusters#cluster/databases#database/procedures#testplanseegenerator statements stmt-3\n"
    "set /clusters#cluster/databases#database/procedures#testplanseegenerator/statements#stmt-3 sqltext \"select A, B, C, count(*) over (partition by A order by B) as R from T ORDER BY A, B, C, R;\"\n"
    "set $PREV querytype 2\n"
    "set $PREV readonly true\n"
    "set $PREV singlepartition true\n"
    "set $PREV replicatedtabledml false\n"
    "set $PREV iscontentdeterministic false\n"
    "set $PREV isorderdeterministic false\n"
    "set $PREV nondeterminismdetail \"\"\n"
    "set $PREV cost 0\n"
    "set $PREV seqscancount 0\n"
    "set $PREV explainplan \"\"\n"
    "set $PREV tablesread \"\"\n"
    "set $PREV tablesupdated \"\"\n"
    "set $PREV indexesused \"\"\n"
    "set $PREV cachekeyprefix \"\"\n"
    "add /clusters#cluster/databases#database/procedures#testplanseegenerator statements stmt-4\n"
    "set /clusters#cluster/databases#database/procedures#testplanseegenerator/statements#stmt-4 sqltext \"select A, B, C, count(A+B) over (partition by A order by B) as R from T ORDER BY A, B, C, R;\"\n"
    "set $PREV querytype 2\n"
    "set $PREV readonly true\n"
    "set $PREV singlepartition true\n"
    "set $PREV replicatedtabledml false\n"
    "set $PREV iscontentdeterministic false\n"
    "set $PREV isorderdeterministic false\n"
    "set $PREV nondeterminismdetail \"\"\n"
    "set $PREV cost 0\n"
    "set $PREV seqscancount 0\n"
    "set $PREV explainplan \"\"\n"
    "set $PREV tablesread \"\"\n"
    "set $PREV tablesupdated \"\"\n"
    "set $PREV indexesused \"\"\n"
    "set $PREV cachekeyprefix \"\"\n"
    "add /clusters#cluster/databases#database/procedures#testplanseegenerator statements stmt-5\n"
    "set /clusters#cluster/databases#database/procedures#testplanseegenerator/statements#stmt-5 sqltext \"select A, B, min(abs(5-C)) over (partition by A order by B) as R from T ORDER BY A, B, R;\"\n"
    "set $PREV querytype 2\n"
    "set $PREV readonly true\n"
    "set $PREV singlepartition true\n"
    "set $PREV replicatedtabledml false\n"
    "set $PREV iscontentdeterministic false\n"
    "set $PREV isorderdeterministic false\n"
    "set $PREV nondeterminismdetail \"\"\n"
    "set $PREV cost 0\n"
    "set $PREV seqscancount 0\n"
    "set $PREV explainplan \"\"\n"
    "set $PREV tablesread \"\"\n"
    "set $PREV tablesupdated \"\"\n"
    "set $PREV indexesused \"\"\n"
    "set $PREV cachekeyprefix \"\"\n"
    "add /clusters#cluster/databases#database/procedures#testplanseegenerator statements stmt-6\n"
    "set /clusters#cluster/databases#database/procedures#testplanseegenerator/statements#stmt-6 sqltext \"select A, B, min(abs(3-C)) over (partition by A order by B) as R from T ORDER BY A, B, R;\"\n"
    "set $PREV querytype 2\n"
    "set $PREV readonly true\n"
    "set $PREV singlepartition true\n"
    "set $PREV replicatedtabledml false\n"
    "set $PREV iscontentdeterministic false\n"
    "set $PREV isorderdeterministic false\n"
    "set $PREV nondeterminismdetail \"\"\n"
    "set $PREV cost 0\n"
    "set $PREV seqscancount 0\n"
    "set $PREV explainplan \"\"\n"
    "set $PREV tablesread \"\"\n"
    "set $PREV tablesupdated \"\"\n"
    "set $PREV indexesused \"\"\n"
    "set $PREV cachekeyprefix \"\"\n"
    "add /clusters#cluster/databases#database/procedures#testplanseegenerator statements stmt-7\n"
    "set /clusters#cluster/databases#database/procedures#testplanseegenerator/statements#stmt-7 sqltext \"select A, B, min(abs(1-C)) over (partition by A order by B) as R from T ORDER BY A, B, R;\"\n"
    "set $PREV querytype 2\n"
    "set $PREV readonly true\n"
    "set $PREV singlepartition true\n"
    "set $PREV replicatedtabledml false\n"
    "set $PREV iscontentdeterministic false\n"
    "set $PREV isorderdeterministic false\n"
    "set $PREV nondeterminismdetail \"\"\n"
    "set $PREV cost 0\n"
    "set $PREV seqscancount 0\n"
    "set $PREV explainplan \"\"\n"
    "set $PREV tablesread \"\"\n"
    "set $PREV tablesupdated \"\"\n"
    "set $PREV indexesused \"\"\n"
    "set $PREV cachekeyprefix \"\"\n"
    "add /clusters#cluster/databases#database/procedures#testplanseegenerator statements stmt-8\n"
    "set /clusters#cluster/databases#database/procedures#testplanseegenerator/statements#stmt-8 sqltext \"select A, B, max(-1 * abs(1-C)) over (partition by A order by B) as R from T ORDER BY A, B, R;\"\n"
    "set $PREV querytype 2\n"
    "set $PREV readonly true\n"
    "set $PREV singlepartition true\n"
    "set $PREV replicatedtabledml false\n"
    "set $PREV iscontentdeterministic false\n"
    "set $PREV isorderdeterministic false\n"
    "set $PREV nondeterminismdetail \"\"\n"
    "set $PREV cost 0\n"
    "set $PREV seqscancount 0\n"
    "set $PREV explainplan \"\"\n"
    "set $PREV tablesread \"\"\n"
    "set $PREV tablesupdated \"\"\n"
    "set $PREV indexesused \"\"\n"
    "set $PREV cachekeyprefix \"\"\n"
    "add /clusters#cluster/databases#database/procedures#testplanseegenerator statements stmt-9\n"
    "set /clusters#cluster/databases#database/procedures#testplanseegenerator/statements#stmt-9 sqltext \"select A, B, max(-1 * abs(3-C)) over (partition by A order by B) as R from T ORDER BY A, B, R;\"\n"
    "set $PREV querytype 2\n"
    "set $PREV readonly true\n"
    "set $PREV singlepartition true\n"
    "set $PREV replicatedtabledml false\n"
    "set $PREV iscontentdeterministic false\n"
    "set $PREV isorderdeterministic false\n"
    "set $PREV nondeterminismdetail \"\"\n"
    "set $PREV cost 0\n"
    "set $PREV seqscancount 0\n"
    "set $PREV explainplan \"\"\n"
    "set $PREV tablesread \"\"\n"
    "set $PREV tablesupdated \"\"\n"
    "set $PREV indexesused \"\"\n"
    "set $PREV cachekeyprefix \"\"\n"
    "",
    3,
    allTables
};


int main() {
     return TestSuite::globalInstance()->runAll();
}
