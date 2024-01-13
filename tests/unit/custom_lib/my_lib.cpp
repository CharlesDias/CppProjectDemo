#include "gtest/gtest.h"

#include "custom_lib/my_lib.h"

namespace
{
TEST(MyLib, SumTest)
{
    EXPECT_EQ(addition(1, 2), 3);
}

TEST(MyLib, SubtractionTest)
{
    EXPECT_EQ(subtraction(1, 2), -1);
}
} // namespace
