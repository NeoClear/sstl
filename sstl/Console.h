#pragma once

#include <iostream>
#include "String.h"

namespace sstl {
    namespace Console {
        void print(Printable& o) {
            std::cout << o.toString();
        }
        void print(String<>& s) {
            std::cout << s;
        }

        #define DEFINE_PRINT_BASIC_TYPES(_Ty)   \
        void print(_Ty t) {                     \
            std::cout << t;                     \
        }

        DEFINE_PRINT_BASIC_TYPES(char)
        DEFINE_PRINT_BASIC_TYPES(unsigned char)
        DEFINE_PRINT_BASIC_TYPES(signed char)
        DEFINE_PRINT_BASIC_TYPES(short)
        DEFINE_PRINT_BASIC_TYPES(unsigned short)
        DEFINE_PRINT_BASIC_TYPES(int)
        DEFINE_PRINT_BASIC_TYPES(unsigned int)
        DEFINE_PRINT_BASIC_TYPES(long)
        DEFINE_PRINT_BASIC_TYPES(unsigned long)
        DEFINE_PRINT_BASIC_TYPES(float)
        DEFINE_PRINT_BASIC_TYPES(double)
        DEFINE_PRINT_BASIC_TYPES(char*)
        DEFINE_PRINT_BASIC_TYPES(const char*)

        void print(bool bVal) {
            std::cout << bVal ? "True" : "False";
        }
    }
}
