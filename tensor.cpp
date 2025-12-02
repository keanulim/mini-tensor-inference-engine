//
// Created by Keanu Lim on 11/29/25.
//
#include "tensor.h"

template<typename T>
Tensor<T>::Tensor(std::vector<int64_t> user_shape)
    :data{0}, shape{user_shape}, strides{shape.size(),1} {
    compute_strides();
};

template<typename T>
Tensor<T>::Tensor(std::vector<int64_t> user_data, std::vector<int64_t> user_shape)
    :data{user_data}, shape{user_shape}, strides{shape.size(),1}{
    compute_strides();
};

template <typename T>
int64_t Tensor<T>::size() const{
    int64_t total = 1;
    for (int i{0}; i < shape.size(); i++) {
        total *= shape[i];
    }
    return total;

}

template<typename T>
void Tensor<T>::compute_strides() {
    std::vector<int64_t> temp(shape.size(),1);
    for (int i = shape.size()-1; i > 0; --i) {
        strides[i] = shape[i+1] * strides[i+1];
    }
}
