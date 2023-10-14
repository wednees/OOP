#include "six.hpp"
#include <algorithm>

using namespace std;

bool is_digit_under_six(char s) {
    return (0 <= s - '0') && (s - '0' < 6);
}

Six::Six() : length{0}, number{nullptr} {}

Six::Six(const initializer_list<unsigned char> & t) {
    initializer_list<unsigned char>::iterator it = t.begin();
    while (*it == '0') {
        ++it;
    }
    if (it == t.end()) {
        --it;
    }
    length = t.end() - it;
    number = new unsigned char[length];
    for (int i = 0; i < length; ++i) {
        int j = t.size() - 1 - i;
        if (!is_digit_under_six(*(t.begin() + j))) throw logic_error("Error occured. Digits must be under 6.");
        number[i] = *(t.begin() + j);
    }
}

Six::Six(const string & t) {
    int start_idx = 0;
    while (t[start_idx] == '0') {
        ++start_idx;
    }
    if (start_idx == t.size()) {
        --start_idx;
    }
    length = t.size() - start_idx;
    number = new unsigned char[length];
    for (int i = 0; i < length; ++i) {
        int j = t.size() - 1 - i;
        if (!is_digit_under_six(t[j])) throw logic_error("Error occured. Digits must be under 6.");
        number[i] = t[j];
    }
}

Six::Six(const Six & other) {
    number = new unsigned char[other.length];
    length = other.length;

    for (int i = 0; i < length; i++) {
        number[i] = other.number[i];
    }
}

Six::Six(Six&& other) noexcept {
    length = other.length;
    number = other.number;

    other.length = 0;
    other.number = nullptr;
}

Six::~Six() noexcept {
    if (length > 0) {
        length = 0;
        delete[] number;
        number = nullptr;
    }
}

int Six::size() const noexcept {
    return length;
}

unsigned char* Six::array() const noexcept {
    return number;
}

ostream& operator<<(ostream & os, const Six & t) {
    int i = t.size();
    while(i--) {
        os << t.array()[i];
    }
    return os;
}

Six& Six::operator=(const Six & t) {
    if (length > 0) {
        delete[] number;
    }
    length = t.length;
    number = new unsigned char[length];

    for (int i = 0; i < length; ++i) {
        number[i] = t.number[i];
    }

    return *this;
}

bool Six::operator==(const Six & t) const {
    if (length != t.length) {
        return false;
    }
    for (int i = 0; i < length; i++) {
        if (number[i] != t.number[i]) {
            return false;
        }
    }
    return true;
}

bool Six::operator!=(const Six & t) const {
    return !(*this == t);
}

bool Six::operator>(const Six & t) const {
    if (length != t.length) {
        return length > t.length;
    }
    int i = length;
    while(i--) {
        if (number[i] != t.number[i]) {
            return number[i] > t.number[i];
        }
    }
    return false;
}

bool Six::operator>=(const Six & t) const {
    return (*this > t) || (*this == t);
}

bool Six::operator<(const Six & t) const {
    return !(*this >= t);
}

bool Six::operator<=(const Six & t) const {
    return !(*this > t);
}

Six Six::operator+(const Six & t) const {
    int final_length = max(length, t.length) + 1;
    string res(final_length, '0');

    for (int i = 0; i < final_length - 1; i++) {
        int sum = ((i < length) ? number[i] - '0' : 0) + ((i < t.length) ? t.number[i] - '0' : 0);
        res[i + 1] += (res[i] - '0' + sum) / base;
        res[i] = (res[i] - '0' + sum) % base + '0';
    }

    reverse(res.begin(), res.end());

    return Six(res);
}

Six& Six::operator+=(const Six & t) {
    *this = *this + t;
    return *this;
}

Six Six::operator-(const Six & t) const {
    if (*this < t) {
        throw logic_error("Error occured. Result must be positive.");
    }

    if (*this == t) {
        return Six("0");
    }

    int final_length = max(length, t.length);
    string res(final_length, '0');

    for (int i = 0; i < final_length - 1; i++) {
        res[i] += number[i] - '0' - ((i < t.length) ? t.number[i] - '0' : 0);
        if (res[i] - '0' < 0) {
            res[i] += base;
            res[i + 1] -= 1;
        }
    }
    res[final_length - 1] += number[final_length - 1] - '0' - ((final_length == t.length) ? t.number[final_length - 1] - '0' : 0);

    reverse(res.begin(), res.end());

    return Six(res);
}

Six& Six::operator-=(const Six & t) {
    *this = *this - t;
    return *this;
}