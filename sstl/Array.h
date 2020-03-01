/*
 * vector
 */

#pragma once

#include <cstddef>
#include <initializer_list>
#include <utility>
#include <memory>
#include "Iterator.h"

namespace sstl {
    constexpr size_t defaultVectorCapacity = 32;
    template<typename _Container, typename _Alloc = std::allocator<_Container>>
    class Array {
    private:
        class ArrayIterator : public _GenericIterator {
        private:
            Array* host;
            _Container* ptr;
        public:
            ArrayIterator() {}
            ArrayIterator(Array* host) : host(host), ptr(host->_meta) {}
            ArrayIterator(Array* host, size_t index) : host(host), ptr(host->_meta + index) {}
            // Need Exception
            void operator++() {
                ptr++;
            }
            void operator--() {
                ptr--;
            }
            bool operator!=(ArrayIterator rhs) {
                return ptr != rhs.ptr;
            }
            void moveForward(size_t steps) {
                ptr += steps;
            }
            void moveBackward(size_t steps) {
                ptr -= steps;
            }
            _Container& operator*() {
                return *ptr;
            }
        };

    private:
        _Alloc _alloc;
    private:
        int _capacity = defaultVectorCapacity;
        int _size = 0;
        _Container* _meta;
        ArrayIterator _begin;
        ArrayIterator _end;

        void eleCopy(_Container* dest, _Container* src, size_t size) {
            for (size_t i = 0; i < size; i++)
                dest[i] = src[i];
        }
        void allocSpace(size_t size) {
            _size = size;
            while (_capacity < _size)
                _capacity <<= 1;
            _meta = _alloc.allocate(_capacity);

            _begin = ArrayIterator(this);
            _end = ArrayIterator(this, _size);
        }
        void extendSpace(size_t size) {
            size_t oldSize = _size;
            size_t oldCapacity = _capacity;
            _size += size;
            _end.moveForward(size);
            if (_size > _capacity) {
                while (_capacity < _size)
                    _capacity <<= 1;
                _Container* newSpace = _alloc.allocate(_capacity);
                eleCopy(newSpace, _meta, oldSize);
                
                _alloc.deallocate(_meta, _capacity);
                _meta = newSpace;
            }
        }
        void shrinkSpace(size_t size) {
            // size_t oldSize = _size;
            // if (_size < size)
            //     throw new exception("not enough space");
            _size -= size;
            _end.moveBackward(size);
        }
    public:
        using Iterator = ArrayIterator;

        Array() {
            allocSpace(0);
        }

        Array(size_t n) {
            allocSpace(n);
        }
        Array(size_t n, _Container init) {
            allocSpace(n);
            for (int i = 0; i < _size; i++)
                _meta[i] = init;
        }
        Array(std::initializer_list<_Container> arr) {
            allocSpace(arr.size());
            int id = 0;
            for (const _Container& ele : arr)
                _meta[id++] = ele;
        }

        int size() { return _size; }
        int capacity() { return _capacity; }
        bool isempty() { return _size == 0; }

        _Container& operator[](size_t index) {
            return _meta[index];
        }

        void push(_Container&& ele) {
            size_t oldSize = _size;
            extendSpace(1);
            _meta[oldSize] = std::forward<_Container>(ele);
        }

        void pop() {
            shrinkSpace(1);
        }

        Iterator begin() {
            return _begin;
        }

        Iterator end() {
            return _end;
        }

        // void extend(std::initializer_list<Container>)
    };
}
