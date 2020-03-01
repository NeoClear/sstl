#pragma once

namespace sstl {
    class Comparable {
    public:
        virtual int compareTo(Comparable& o) = 0;
    };
}