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
    std::vector<int64_t> strides;
    void compute_strides();
public:
    int64_t size() const;


};

#endif //MINI_TENSOR_INFERENCE_ENGINE_TENSOR_H