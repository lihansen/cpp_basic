#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write some test cases for each function.
//-----------------------------------------------------------------------------
TEST(MyVector, Test_IsPalindrome) {
    CPPLib cpplib;
    const std::string test_str1 = "";
    const std::string test_str2 = "a";
    const std::string test_str3 = "12c21";
    const std::string test_str4 = "abba";
    const std::string test_str5 = "abbbcc";
    auto res1 = cpplib.IsPalindrome(test_str1);
    auto res2 = cpplib.IsPalindrome(test_str2);
    auto res3 = cpplib.IsPalindrome(test_str3);
    auto res4 = cpplib.IsPalindrome(test_str4);
    auto res5 = cpplib.IsPalindrome(test_str5);
    EXPECT_EQ(true, res1);
    EXPECT_EQ(true, res2);
    EXPECT_EQ(true, res3);
    EXPECT_EQ(true, res4);
    EXPECT_EQ(false, res5);
}

TEST(MyVector, Test_CheckValidExpression){
    CPPLib cpplib;
    const std::string test_str1 = "(a+b)";
    const std::string test_str2 = "(a+b)[c*d]{5g+h}";
    const std::string test_str3 = "(a+b]";
    const std::string test_str4 = "(7h+[5c)+7]";
    const std::string test_str5 = "{2k+[5j]}";
    const std::string test_str6 = "{2k++[5--*j]}";
    const std::string test_str7 = "";
    const std::string test_str8 = "abc";

    auto res1 = cpplib.CheckValidExpression(test_str1);
    auto res2 = cpplib.CheckValidExpression(test_str2);
    auto res3 = cpplib.CheckValidExpression(test_str3);
    auto res4 = cpplib.CheckValidExpression(test_str4);
    auto res5 = cpplib.CheckValidExpression(test_str5);
    auto res6 = cpplib.CheckValidExpression(test_str6);
    auto res7 = cpplib.CheckValidExpression(test_str7);
    auto res8 = cpplib.CheckValidExpression(test_str8);
    EXPECT_EQ(true, res1);
    EXPECT_EQ(true, res2);
    EXPECT_EQ(false, res3);
    EXPECT_EQ(false, res4);
    EXPECT_EQ(true, res5);
    EXPECT_EQ(true, res6);
    EXPECT_EQ(true, res7);
    EXPECT_EQ(true, res8);
}

TEST(MyVector, Test_OddChar){
    CPPLib cpplib;
    const std::string test_str1 = "abcba";
    const std::string test_str2 = "c";
    const std::string test_str3 = "ababc";
    const std::string test_str4 = "";

    auto res1 = cpplib.OddChar(test_str1);
    auto res2 = cpplib.OddChar(test_str2);
    auto res3 = cpplib.OddChar(test_str3);
    auto res4 = cpplib.OddChar(test_str4);
    EXPECT_EQ(2, res1);
    EXPECT_EQ(0, res2);
    EXPECT_EQ(4, res3);
    EXPECT_EQ(-1, res4);
    
    
}