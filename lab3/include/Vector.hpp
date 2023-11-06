#pragma once
#include<iostream>
#include "figure.hpp"

class Vector
{
    public:
        Vector();
        void resize(int new_size);
        int  size() const;
        void push_back(Figure* val);
        void remove(int ind);
        Figure* & operator[] (int idx);

        ~Vector();
    private:
        Figure** buf;
        int size_;
        int cap;
};