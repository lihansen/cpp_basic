#include "src/lib/cpplib.h"

#include <map>
#include <vector>

#include "gtest/gtest.h"

// Add your own tests in this file
TEST(Q7_Student, BasicTest) {
  CPPLib cpplib;
  auto actual = cpplib.climbStairs(0);
  auto actual1 = cpplib.climbStairs(1);
  auto actual2 = cpplib.climbStairs(2);
  EXPECT_EQ(0,actual);
  EXPECT_EQ(1,actual1);
  EXPECT_EQ(2,actual2);
}

TEST(Q7_Student, GivenExample) {
  CPPLib cpplib;
  auto actual = cpplib.climbStairs(4);
  EXPECT_EQ(5, actual);
}


TEST(Q7_Student, LargestInput) {
  CPPLib cpplib;
  auto actual = cpplib.climbStairs(45);
  EXPECT_EQ(1836311903, actual);
}

TEST(Q7_Student, OutofRange) {
  CPPLib cpplib;
  auto actual = cpplib.climbStairs(50);
  EXPECT_EQ(-1, actual);
}