// ----------------------------------------------------------------------------
// Copyright 2017 Nervana Systems Inc.
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// ----------------------------------------------------------------------------

#include "ngraph/ops/tanh.hpp"
#include "ngraph/ops/cosh.hpp"
#include "ngraph/ops/divide.hpp"
#include "ngraph/ops/multiply.hpp"

void ngraph::op::Tanh::generate_adjoints(autodiff::Adjoints& adjoints,
                                         const std::shared_ptr<Node>& delta)
{
    auto x = m_arguments[0];

    auto c = std::make_shared<op::Cosh>(x);

    adjoints.add_delta(x, delta / (c * c));
}