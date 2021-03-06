/**
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */
#pragma once

#if ENABLE(DFG_JIT)

namespace JSC { namespace DFG {

class Graph;

// Inserts store barriers in a block-local manner without consulting the abstract interpreter.
// Uses a simple epoch-based analysis to avoid inserting barriers on newly allocated objects. This
// phase requires that we are not in SSA.
bool performFastStoreBarrierInsertion(Graph&);

// Inserts store barriers using a global analysis and consults the abstract interpreter. Uses a
// simple epoch-based analysis to avoid inserting barriers on newly allocated objects. This phase
// requires SSA. This phase also requires having valid AI and liveness.
bool performGlobalStoreBarrierInsertion(Graph&);

} } // namespace JSC::DFG

#endif // ENABLE(DFG_JIT)
