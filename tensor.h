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
    std::vector<int64_t> shape;
    std::vector<T> data;
    std::vector<int64_t> strides;
    void compute_strides();
public:
    Tensor() = default;
    explicit Tensor(const std::vector<int64_t>& user_shape); // constructor shape only
    Tensor(const std::vector<int64_t>& user_shape, const std::vector<T>& user_data); //shape and data
    int64_t size() const;
    int64_t compute_index(const std::vector<int64_t>& index) const;
};

#endif //MINI_TENSOR_INFERENCE_ENGINE_TENSOR_H