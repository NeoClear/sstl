#pragma once

#include "String.h"

namespace sstl {
    class Printable {
    public:
        virtual String<> toString() = 0;
    };
}