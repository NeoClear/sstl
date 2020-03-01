#pragma once

#include <cstddef>

namespace sstl {
    class Hashable {
    public:
        virtual size_t hashValue() = 0;
    };
}
