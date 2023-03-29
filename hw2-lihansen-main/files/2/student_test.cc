#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write some test cases for each function.
//-----------------------------------------------------------------------------
TEST(IndexOfFirstSpace, test1) {
    CPPLib cpplib;
    std::string input = "My Drive";
    auto actual = cpplib.IndexOfFirstSpace(input);
    EXPECT_EQ(2, actual);
}
//-----------------------------------------------------------------------------
TEST(SeparateFirstAndLastNames, test1) {
    CPPLib cpplib;
    std::string fullname = "Hansen Li";
    std::string firstname = "";
    std::string lastname = "";
    cpplib.SeparateFirstAndLastNames(fullname, firstname, lastname);
    auto actual_firstname = "Hansen";
    auto actual_lastname = "Li";
    EXPECT_EQ(actual_firstname, firstname);
    EXPECT_EQ(actual_lastname, lastname);
    
}
//-----------------------------------------------------------------------------
TEST(NumberOfVowels, test1) {
    CPPLib cpplib;
    std::string test_str1 = "Hansen";
    std::string test_str2 = " ";
    auto num1 = cpplib.NumberOfVowels(test_str1);
    auto num2 = cpplib.NumberOfVowels(test_str2);
    EXPECT_EQ(2, num1);
    EXPECT_EQ(0, num2);

}
//-----------------------------------------------------------------------------
TEST(NumberOfConsonants, test1) {
    CPPLib cpplib;
    std::string test_str1 = "Hansen";
    std::string test_str2 = " a";
    auto num1 = cpplib.NumberOfConsonants(test_str1);
    auto num2 = cpplib.NumberOfConsonants(test_str2);
    EXPECT_EQ(4, num1);
    EXPECT_EQ(1, num2);
}
//-----------------------------------------------------------------------------
TEST(Reverse, test1) {
    CPPLib cpplib;
    std::string test_str1 = "abcd";
    std::string test_str2 = "a";
    std::string test_str3 = "";
    auto status1 = cpplib.Reverse(test_str1);
    auto status2 = cpplib.Reverse(test_str2);
    auto status3 = cpplib.Reverse(test_str3);
    EXPECT_EQ(0, status1);
    EXPECT_EQ(0, status2);
    EXPECT_EQ(0, status3);
    EXPECT_EQ("dcba", test_str1);
    EXPECT_EQ("a", test_str2);
    EXPECT_EQ("", test_str3);
}

