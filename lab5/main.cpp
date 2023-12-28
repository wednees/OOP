#include "stack.hpp"
#include "allocator.hpp"
#include <map>
#include <iostream>

int fact(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return fact(n - 1) * n;
}

int main() {
    std::map<int, int, std::less<int>, MyOwn::Allocator<std::pair<const int, int>>> m;
    for (int i = 0; i < 10; ++i) {
        m[i] = fact(i);
    }
    for (auto el : m) {
        std::cout << el.first << ' ' << el.second << std::endl;
    }
    std::cout << std::endl;
    MyOwn::Stack<int, MyOwn::Allocator<int>> s;
    for (int i = 0; i < 10; ++i) {
        s.push(i);
    }
    for (auto el : s) {
        std::cout << el << std::endl;
    }

    return 0;
}
