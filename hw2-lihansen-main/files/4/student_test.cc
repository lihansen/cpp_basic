
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write several test cases for each function.
//-----------------------------------------------------------------------------
TEST(CapitalizeFirstLetter, test1) {
    CPPLib cpplib;
    std::string test_str1 = "";
    std::string test_str2 = "*#06#";
    std::string test_str3 = "Hansen";
    auto fail1 = cpplib.CapitalizeFirstLetter(test_str1);
    auto fail2 = cpplib.CapitalizeFirstLetter(test_str2);
    auto fail3 = cpplib.CapitalizeFirstLetter(test_str3);
    EXPECT_EQ(false, fail1);
    EXPECT_EQ(false, fail2);
    EXPECT_EQ(false, fail3);
    EXPECT_EQ("", test_str1);
    EXPECT_EQ("*#06#", test_str2);
    EXPECT_EQ("Hansen", test_str3);
}
//-----------------------------------------------------------------------------

TEST(CapitalizeFirstLetter, test2) {
    CPPLib cpplib;
    std::string test_str1 = "hansen";
    std::string test_str2 = "aa";
    std::string test_str3 = "z";
    auto succ1 = cpplib.CapitalizeFirstLetter(test_str1);
    auto succ2 = cpplib.CapitalizeFirstLetter(test_str2);
    auto succ3 = cpplib.CapitalizeFirstLetter(test_str3);
    EXPECT_EQ(true, succ1);
    EXPECT_EQ(true, succ2);
    EXPECT_EQ(true, succ3);
    EXPECT_EQ("Hansen", test_str1);
    EXPECT_EQ("Aa", test_str2);
    EXPECT_EQ("Z", test_str3);
}
//-----------------------------------------------------------------------------
