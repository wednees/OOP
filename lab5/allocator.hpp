#pragma once

#include <iostream>
#include <vector>

using namespace std;

//#define DEBUG

namespace MyAlloc
{
    template <class T>
    class Allocator
    {
    private:
        vector<T> _used_blocks; // char *_used_blocks;
        vector<T *> _free_blocks; // void **_free_blocks;
        uint64_t _free_count;

    public:
        static constexpr size_t max_count = 100000;
        using value_type = T;
        using pointer = T *;
        using const_pointer = const T *;
        using size_type = size_t;

        Allocator()
        {
            _used_blocks.resize(max_count); // = (char *)malloc(sizeof(T) * max_count);
            _free_blocks.resize(max_count); // = (void **)malloc(sizeof(void *) * max_count);

            for (uint64_t i = 0; i < max_count; i++)
                _free_blocks[i] = &_used_blocks[i];
            _free_count = max_count;
#ifdef DEBUG
            cout << "allocator: memory init" << endl;
#endif
        }

        ~Allocator()
        {
#ifdef DEBUG
            if (_free_count < max_count)
                cout << "allocator: Memory leak?" << endl;
            else
                cout << "allocator: Memory freed" << endl;
#endif
        }

        template <class U>
        struct rebind {
            using other = Allocator<U>;
        };

        T *allocate(size_t n){
            if (_free_count < n){
                cout << "No memory left ._." << endl;
                exit (-1);  
            }
            else{
                T *result = malloc(n * sizeof(T));
                for (int i = 0; i < n; ++i){
                    result[i] = (T *)_free_blocks[_free_count - i];
                } 
            }
            return result;
            // T *result = malloc(n * sizeof(T));
            // for(int i = 0; i < n; ++i){
            // if (_free_count > 0)
            // {
            //     result = (T *)_free_blocks[--_free_count];
            // }
            // else
            // {
            //     cout << "No memory left ._." << endl;
            // }
            // }
            // return result;
        }

        void deallocate(T *pointer, size_t)
        {
#ifdef DEBUG
            cout << "allocator: Deallocate block " << endl;
#endif
            _free_blocks[_free_count++] = pointer;
        }
    };

    template <class T, class U>
    constexpr bool operator==(const Allocator<T> &lhs, const Allocator<U> &rhs) 
    {
        return true;
    }

    template <typename T, typename U, size_t BLOCK_COUNT>
    constexpr bool operator!=(const Allocator<T> &lhs, const Allocator<U> &rhs)  
    {
        return false;
    }
}