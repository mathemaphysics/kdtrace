#include "kdtrace/kdtrace.hpp"
#include "gtest/gtest.h"

using namespace kdtrace;

TEST(AdditionTests, AddOneTest)
{
  EXPECT_EQ(add_one(0), 1);
  EXPECT_EQ(add_one(123), 124);
  EXPECT_EQ(add_one(-1), 0);
}

