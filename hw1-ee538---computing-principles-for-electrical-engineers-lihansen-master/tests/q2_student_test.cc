// NOTE: Add your own q2 tests in this file
#include "src/lib/cpplib.h"

#include <map>
#include <vector>

#include "gtest/gtest.h"

// Add your own tests in this file
TEST(Q2_Student, ZeroSize)
{
  CPPLib cpplib;
  std::vector<int> inputs2 = {};
  auto actual2 = cpplib.FindAverage(inputs2);

  EXPECT_EQ(-1, actual2);
}

TEST(Q2_Student, BasicTest)
{
  CPPLib cpplib;
  std::vector<int> inputs = {1, 2, 3, 10};
  std::vector<int> inputs1 = {1, -2, 1};
  auto actual = cpplib.FindAverage(inputs);
  auto actual1 = cpplib.FindAverage(inputs1);

  EXPECT_EQ(4, actual);
  EXPECT_EQ(0, actual1);
}