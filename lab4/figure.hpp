#pragma once

#include <iostream>
#include <string>
#include <cmath>
#include "point.hpp"

template <typename T>
class Figure{
    public:
        Figure() = default;

        virtual T square() const = 0;
        virtual Point<T> center() const = 0; 
        virtual operator double() const = 0;
         
        ~Figure() = default; 
};