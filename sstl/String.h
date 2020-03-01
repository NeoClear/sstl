#pragma once

#include <cstring>
#include <utility>
#include <memory>
#include <iostream>
#include "Comparable.h"

namespace sstl {
    template<typename _Container = char, typename _Alloc = std::allocator<_Container>>
    class String : public Comparable {
    private:
        using CharType = _Container;
        _Alloc _alloc;
        CharType* meta;
        size_t _length = 0;
    public:
        String(const char* init) {
            _length = strlen(init);
            meta = _alloc.allocate(_length + 1);
            meta[_length] = '\0';
            memcpy(meta, init, sizeof(CharType) * _length);
        }
        size_t length() { return _length; }
        const CharType* cStr() { return meta; }

        friend std::ostream& operator<<(std::ostream& os, String<>& s) {
            os << s.cStr();
            return os;
        }

        friend std::ostream& operator<<(std::ostream& os, String<>&& s) {
            os << std::move(s.cStr());
            return os;
        }

        CharType& get(size_t index) {
            return meta[index];
        }

        CharType& operator[](size_t index) {
            return get(index);
        }

        bool operator==(String& rhs) {
            return this->compareTo(rhs) == 0;
        }

        bool operator!=(String& rhs) {
            return this->compareTo(rhs) != 0;
        }

        int compareTo(Comparable& o) override {
            String<>& rhs = static_cast<String<>&>(o);
            for (size_t i = 0; i < this->length() && i < rhs.length(); i++) {
                if (this->get(i) == rhs[i])
                    continue;
                return this->get(i) < rhs[i] ? -1 : 1;
            }
            if (this->length() == rhs.length())
                return 0;
            return this->length() < rhs.length() ? -1 : 1;
        }
    };
}
