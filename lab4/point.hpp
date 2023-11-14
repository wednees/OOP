#pragma once

#include <iostream>

template<class T>
class Point
{
    template<class F>
    friend Point<F> operator + (const Point<F>& t, const Point<F>& other);
    template<class F>
    friend Point<F> operator - (const Point<F>& t, const Point<F>& other);
    template<class F>
    friend bool operator == (const Point<F>& t, const Point<F>& other);
    template<class F>
    friend bool operator != (const Point<F>& t, const Point<F>& other);

    template<class F>
    friend std::istream& operator >> (std::istream& is, Point<F>& p);
    template<class F>
    friend std::ostream& operator << (std::ostream& os, const Point<F>& p);

public:
    Point();
    Point(const Point<T>& other);
    Point(T x, T y);

    Point<T>& operator =(const Point<T>& other);

    T x_{};
    T y_{};
};  



template<class T>
Point<T>::Point() : x_{0}, y_{0} {}

template<class T>
Point<T>::Point(T x, T y): x_{x}, y_{y} {}

template<class T>
Point<T>::Point(const Point<T> &other) : x_(other.x_), y_(other.y_) {}

template<class T>
Point<T> operator + (const Point<T>& t, const Point<T>& other){
    return Point<T>(t.x_ + other.x_, t.y_ + other.y_);
}

template<class T>
Point<T> operator - (const Point<T>& t, const Point<T>& other){
    return Point<T>(t.x_ - other.x_, t.y_ - other.y_);
}

template<class T>
bool operator == (const Point<T>& t, const Point<T>& other){
    return (t.x_ == other.x_) && (t.y_ == other.y_);
}

template<class T>
bool operator != (const Point<T> &t, const Point<T> &other){
    return (t.x_ != other.x_) || (t.y_ != other.y_);
}

template<class T>
Point<T>& Point<T>::operator = (const Point<T> &other){
    if (this != &other) {
        x_ = other.x_;
        y_ = other.y_;
    }
    return *this;
}

template<class T>
std::istream& operator >> (std::istream &is, Point<T> &p){
    T x, y;
    is >> x >> y;
    p.x_ = x;
    p.y_ = y;
    return is;
}

template<class T>
std::ostream& operator<<(std::ostream& os, const Point<T>& p){
    os << "x  " << p.x_ << ", y  " << p.y_;
    return os;
}