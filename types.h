//
// Created by Keanu Lim on 12/6/25.
//

#ifndef MINI_TENSOR_INFERENCE_ENGINE_TYPES_H
#define MINI_TENSOR_INFERENCE_ENGINE_TYPES_H
#include <functional>
#include <memory>
#include<vector>

class Tensor;

using TensorPtr = std::shared_ptr<Tensor>;

using KernelFn = std::function<TensorPtr(const std::vector<TensorPtr>&)>;

#endif //MINI_TENSOR_INFERENCE_ENGINE_TYPES_H