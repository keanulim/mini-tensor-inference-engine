//
// Created by Keanu Lim on 11/29/25.
//
#include "tensor.h"
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
    for (int i = shape.size()-1; i > 0; i--) {
        if (i == shape.size()-1) {
            strides[i] = 1;
        }
        else {
            strides[i] = shape[i+1] * strides[i+1];
        }
    }
}
