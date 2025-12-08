//
// Created by Keanu Lim on 12/5/25.
//

#ifndef MINI_TENSOR_INFERENCE_ENGINE_KERNELREGISTRY_H
#define MINI_TENSOR_INFERENCE_ENGINE_KERNELREGISTRY_H

#include <map>
#include <string>
#include "types.h"

#define REGISTER_KERNEL(op_name, kernel_func) \
    namespace { \
        struct Register_##op_name { \
            Register_##op_name() { \
                KernelRegistry::register_kernel(#op_name, kernel_func); \
            } \
        }; \
        static Register_##op_name global_register_##op_name; \
    }

class KernelRegistry {
private:
    std::map<std::string, KernelFn> registry_;
public:
    static void register_kernel(const std::string& op_type, KernelFn kernel_func);
    static KernelFn lookup_kernel(const std::string& op_type);
};

#endif //MINI_TENSOR_INFERENCE_ENGINE_KERNELREGISTRY_H