#include <gtest/gtest.h>
#include "task.h"

TEST(test_01, basic_test_set)
{
    ASSERT_TRUE(task(2,7)==11);
}

TEST(test_02, basic_test_set)
{
    ASSERT_TRUE(task(0,0)==0);
}

TEST(test_03, basic_test_set)
{
    ASSERT_TRUE(task(-7,-2)==11);
}

TEST(test_04, basic_test_set)
{
    ASSERT_TRUE(task(111,111)==6);
}

TEST(test_05, basic_test_set)
{
    ASSERT_TRUE(task(-111,-111)==6);
}

TEST(test_06, basic_test_set)
{
    ASSERT_TRUE(task(-7,-2)==11);
}

TEST(test_07, basic_test_set)
{
    ASSERT_TRUE(task(-1,2)==3);
}

TEST(test_08, basic_test_set)
{
    ASSERT_TRUE(task(1,10)==17);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}