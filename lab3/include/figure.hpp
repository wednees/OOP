#pragma once

#include <iostream>
#include <string>
#include <cmath>
#include "point.hpp"

class Figure{
    public:
        Figure() = default; 
        virtual double square() const = 0;
        virtual Point center() const = 0; 
        virtual operator double() const = 0; 
        ~Figure() = default; 
};