#include "src/lib/cpplib.h"

#include <map>
#include <vector>

#include "gtest/gtest.h"

// Add your own tests in this file
TEST(Q6_Student, BasicTest) {
  CPPLib cpplib;
  std::vector< std::vector< std::vector<int> > > input = {{{1, 2}, {3, 4}}, {{5}, {6}, {}}, {{7, 8}}};
  std::vector<int> res = {1,2,3,4,5,6,7,8};
  auto actual = cpplib.Flatten3DVector(input);
  EXPECT_EQ(res, actual);
}

TEST(Q6_Student, ZeroElems){
  CPPLib cpplib;
  std::vector< std::vector< std::vector<int> > > input = {{{}}};
  std::vector< std::vector< std::vector<int> > > input1 = {{},{{}}};
  std::vector<int> res = {};
  auto actual = cpplib.Flatten3DVector(input);
  auto actual1 = cpplib.Flatten3DVector(input1);
  EXPECT_EQ(res, actual);
  EXPECT_EQ(res, actual);
}