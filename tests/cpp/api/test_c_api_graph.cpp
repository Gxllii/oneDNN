/*******************************************************************************
* Copyright 2020 Intel Corporation
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/

#include <gtest/gtest.h>

#include "oneapi/dnnl/dnnl_graph.h"

#include "test_api_common.h"

TEST(c_api_test, create_graph_by_device) {
    dnnl_graph_graph_t *agraph = NULL;
    dnnl_graph_engine_kind_t engine = dnnl_graph_cpu;

#define CREATE_GRAPH_BY_DEVICE_DESTROY \
    do { \
        dnnl_graph_graph_destroy(agraph); \
        agraph = NULL; \
    } while (0);

    ASSERT_EQ_SAFE(dnnl_graph_graph_create(&agraph, engine),
            dnnl_graph_result_success, CREATE_GRAPH_BY_DEVICE_DESTROY);
    CREATE_GRAPH_BY_DEVICE_DESTROY;
#undef CREATE_GRAPH_BY_DEVICE_DESTROY
}
