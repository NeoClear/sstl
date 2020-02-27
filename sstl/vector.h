/*
 * vector
 */

#pragma once

#include <cstddef>
#include <initializer_list>
#include <utility>
#include <memory>

namespace sstl {
    constexpr size_t defaultVectorCapacity = 32;
    template<typename _Container, typename _Alloc = std::allocator<_Container>>
    class vector {
    private:
        _Alloc _alloc;
    private:
        int _capacity = defaultVectorCapacity;
        int _size = 0;
        _Container* _meta;
        void eleCopy(_Container* dest, _Container* src, size_t size) {
            for (size_t i = 0; i < size; i++)
                dest[i] = src[i];
        }
        void allocSpace(size_t size) {
            _size = size;
            while (_capacity < _size)
                _capacity <<= 1;
            _meta = _alloc.allocate(_capacity);
        }
        void extendSpace(size_t size) {
            size_t oldSize = _size;
            size_t oldCapacity = _capacity;
            _size += size;
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
        }
    public:
        vector() {
            allocSpace(0);
        }

        vector(size_t n) {
            allocSpace(n);
        }
        vector(size_t n, _Container init) {
            allocSpace(n);
            for (int i = 0; i < _size; i++)
                _meta[i] = init;
        }
        vector(std::initializer_list<_Container> arr) {
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

        void push_back(_Container&& ele) {
            size_t oldSize = _size;
            extendSpace(1);
            _meta[oldSize] = std::forward<_Container>(ele);
        }

        void pop_back() {
            shrinkSpace(1);
        }

        // void extend(std::initializer_list<Container>)
    };
}
