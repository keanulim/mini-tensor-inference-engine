//
// Created by Keanu Lim on 11/29/25.
//

#ifndef MINI_TENSOR_INFERENCE_ENGINE_TENSOR_H
#define MINI_TENSOR_INFERENCE_ENGINE_TENSOR_H
#include <vector>
#include <cstdint>

template<typename T>
class Tensor {
private:
    std::vector<T> data;
    std::vector<int64_t> shape;
public:
    int64_t size() const;

};

#endif //MINI_TENSOR_INFERENCE_ENGINE_TENSOR_H