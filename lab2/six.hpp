#pragma once
#include <string>
#include <iostream>

using namespace std;

class Six {
public:
    Six();
    Six(const initializer_list<unsigned char> & t);
    Six(const string & t);
    Six(const Six & other);
    bool operator==(const Six & t) const;
    bool operator!=(const Six & t) const;
    bool operator>(const Six & t) const;
    bool operator>=(const Six & t) const;
    bool operator<(const Six & t) const;
    bool operator<=(const Six & t) const;
    Six& operator=(const Six & t);
    Six operator+(const Six & t);
    Six operator-(const Six & t);
    int size() const noexcept;
    unsigned char* array() const noexcept;
    ~Six() noexcept;
private:
    int length;
    unsigned char* number;
    const int base = 6;
};

ostream& operator<<(ostream & os, const Six & t);