#include <iostream>
#include <vector>

#include "gtest/gtest.h"
#include "q.h"

// Write several test cases for each function.
//-----------------------------------------------------------------------------
// Make sure you add some test cases to check for nullptr.
TEST(ConcatenateDynamicArrays, test1) {
    CPPLib cpplib;
    int size1 = 2;
    int size2 = 3;
    int arr1 [] = {1,2};
    int arr2 [] = {2,3,4}; 
    int res [size1 + size2] = {1,2,2,3,4};
    auto actual = cpplib.Concatenate(arr1, size1, arr2, size2);

    for (int i = 0; i < size1+size2; i++)
    {
        /* code */
        EXPECT_EQ(res[i], actual[i]);
    }
    
    int zero = 0;
    int arr3[] = {};
    int arr4[] = {};
    auto actual2 = cpplib.Concatenate(arr3, zero, arr4, zero);
    EXPECT_EQ(actual2, nullptr);
}
//-----------------------------------------------------------------------------

TEST(ConcatenateVectors, test2) {
    CPPLib cpplib;
    std::vector <int> vec1 = {1,2};
    std::vector <int> vec2 = {2,3,4};
    std::vector <int> res = {1,2,2,3,4};

    std:: vector <int> vec3 = {};
    std::vector <int> vec4 = {};
    std::vector <int> res2 = {};
    auto actual = cpplib.Concatenate(vec1,vec2);
    auto actual2 = cpplib.Concatenate(vec3,vec4);
    EXPECT_EQ(res, actual);
    EXPECT_EQ(res2, actual2);
}
//-----------------------------------------------------------------------------
