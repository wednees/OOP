#include <gtest/gtest.h>
#include "../include/stack.hpp"
#include "../include/allocator.hpp"

TEST(stack_test, 01) {
    MyOwn::Stack<int, MyOwn::Allocator<int>> s;
    ASSERT_TRUE(s.size() == 0);
}

TEST(stack_test, 02) {
    MyOwn::Stack<int, MyOwn::Allocator<int>> s;
    for (int i = 0; i < 5; ++i) {
        s.push(i);
    }
    MyOwn::Stack<int, MyOwn::Allocator<int>> other(s);
    ASSERT_TRUE(other.size() == 5);
}

TEST(stack_test, 03) {
    MyOwn::Stack<double, MyOwn::Allocator<double>> s;
    ASSERT_TRUE(s.size() == 0);
}

TEST(stack_test, 04) {
    MyOwn::Stack<double, MyOwn::Allocator<double>> s;
    for (int i = 0; i < 5; ++i) {
        s.push(i);
    }
    MyOwn::Stack<double, MyOwn::Allocator<double>> other(s);
    ASSERT_TRUE(other.size() == 5);
}


TEST(stack_test, 05) {
    MyOwn::Stack<int, MyOwn::Allocator<int>> s;
    for (int i = 0; i < 5; ++i) {
        s.push(i);
    }

    ASSERT_TRUE(s.top() == 4);

    s.pop();

    ASSERT_TRUE(s.top() == 3);
}

TEST(stack_test, 06) {
    MyOwn::Stack<double, MyOwn::Allocator<double>> s;
    for (int i = 0; i < 5; ++i) {
        s.push(i);
    }

    ASSERT_TRUE(s.top() == 4.0);

    s.pop();
    
    ASSERT_TRUE(s.top() == 3.0);
}

TEST(stack_test, 07) {
    MyOwn::Stack<int, MyOwn::Allocator<int>> s;
    s.push(1);
    auto iter = s.begin();
    ASSERT_TRUE(*iter == 1);
}

TEST(stack_test, 08) {
    MyOwn::Stack<double, MyOwn::Allocator<double>> s;
    s.push(1.0);
    auto iter = s.begin();
    ASSERT_TRUE(*iter == 1.0);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
