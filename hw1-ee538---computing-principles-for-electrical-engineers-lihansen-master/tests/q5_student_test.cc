#include "src/lib/cpplib.h"

#include <map>
#include <vector>

#include "gtest/gtest.h"

// Add your own tests in this file
TEST(Q5_Student, ReturnIntro)
{
  CPPLib cpplib;
  std::string s = "name: Hansen Li \n"
                  "email: hansenli @usc.edu \n"
                  "major: ECE-Machine Learning and Data Science \n"
                  "hobby: coding.";
  auto actual = cpplib.PrintIntro();
  EXPECT_EQ(s, actual);
}