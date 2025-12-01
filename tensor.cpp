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