//
// Created by Keanu Lim on 11/29/25.
//
#include "tensor.h"

template<typename T>
Tensor<T>::Tensor(const std::vector<int64_t>& user_shape)
    :shape(user_shape), data(size()), strides(shape.size()) {
    compute_strides();
};

template<typename T>
Tensor<T>::Tensor(const std::vector<int64_t>& user_shape, const std::vector<T>& user_data)
    :shape(user_shape), data(user_data), strides(shape.size()){
    assert(user_data.size()==size());
    compute_strides();
};

template <typename T>
int64_t Tensor<T>::size() const{
    int64_t total = 1;
    for(int64_t i{0}; i < shape.size(); i++) {
        total *= shape[i];
    }
    return total;
}

template<typename T>
void Tensor<T>::compute_strides() {
    if (shape.empty()) return;

    strides[shape.size()-1] = 1;
    for (int64_t i = shape.size()-2; i >= 0; --i) {
        strides[i] = shape[i+1] * strides[i+1];
    }
}

template<typename T>
int64_t Tensor<T>::compute_index(const std::vector<int64_t>& index) const{
    assert(index.size()==shape.size());
    int64_t offset{0};
    for (int64_t i{0}; i < index.size(); ++i) {
        assert(index[i] >= 0 && index[i] < shape[i]);
        offset+= strides[i]*index[i];
    }
    return offset;
}

