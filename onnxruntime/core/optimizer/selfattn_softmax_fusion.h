// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#pragma once

#include "core/optimizer/graph_transformer.h"

namespace onnxruntime {

/**
@Class BiasSoftmaxFusion
Fuse Add + Softmax to BiasSoftmax
*/
class SelfAttnSoftmaxFusion : public GraphTransformer {
 public:
  SelfAttnSoftmaxFusion(const std::unordered_set<std::string>& compatible_execution_providers = {}) noexcept
      : GraphTransformer("SelfAttnSoftmaxFusion", compatible_execution_providers) {
  }

  Status ApplyImpl(Graph& graph, bool& modified, int graph_level, const logging::Logger& logger) const override;
};

}  // namespace onnxruntime