#include <iostream>
#include <vector>

#include "gtest/gtest.h"
#include "q.h"

// Write several test cases for each function.
//-----------------------------------------------------------------------------
TEST(UniqueVectorNotBySet, test1) {
    CPPLib cpplib;
    std::vector <int> vec1 = {1,2,2,4};
    std::vector <int> res1 = {1,2,4};
    std::vector <int> vec2 = {};
    std::vector <int> res2 = {};
    std::vector <int> vec3 = {1};
    std::vector <int> res3 = {1};
    cpplib.UniqueVectorNotBySet(vec1);
    cpplib.UniqueVectorNotBySet(vec2);
    cpplib.UniqueVectorNotBySet(vec3);
    EXPECT_EQ(vec1,res1);
    EXPECT_EQ(vec2,res2);
    EXPECT_EQ(vec3,res3);    

}
//-----------------------------------------------------------------------------
TEST(UniqueVectorBySet, test1) {
    CPPLib cpplib;
    std::vector <int> vec1 = {1,2,2,4};
    std::vector <int> res1 = {1,2,4};
    std::vector <int> vec2 = {};
    std::vector <int> res2 = {};
    std::vector <int> vec3 = {1};
    std::vector <int> res3 = {1};
    cpplib.UniqueVectorBySet(vec1);
    cpplib.UniqueVectorBySet(vec2);
    cpplib.UniqueVectorBySet(vec3);
    EXPECT_EQ(vec1,res1);
    EXPECT_EQ(vec2,res2);
    EXPECT_EQ(vec3,res3);  
}
//-----------------------------------------------------------------------------
TEST(IntersectVectors, test2) {
    CPPLib cpplib;
    std::vector <int> vec1a = {1,2,2,3};
    std::vector <int> vec1b = {3,4,4,5};
    std::vector <int> res1 = {1,2,3,4,5};
    std::vector <int> vec2a = {};
    std::vector <int> vec2b = {};
    std::vector <int> res2 = {};
    std::vector <int> vec3a = {1};
    std::vector <int> vec3b = {};
    std::vector <int> res3 = {1};
    auto actual1 = cpplib.IntersectVectors(vec1a, vec1b);
    auto actual2 = cpplib.IntersectVectors(vec2a, vec2b);
    auto actual3 = cpplib.IntersectVectors(vec3a, vec3b);
    EXPECT_EQ(actual1,res1);
    EXPECT_EQ(actual2,res2);
    EXPECT_EQ(actual3,res3);
}