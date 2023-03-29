#include <iostream>
#include <vector>

#include "gtest/gtest.h"
#include "q.h"
// Write several test cases for each function.
//-----------------------------------------------------------------------------
TEST(SwapByPointer, test1) {
    CPPLib cpplib;
    float *n1 = new float(1.1);
    float *n2 = new float(0.0);
    cpplib.SwapByPointer(n1, n2);
    EXPECT_EQ(float(1.1), *n2);
    EXPECT_EQ(float(0.0), *n1);
}
//-----------------------------------------------------------------------------

TEST(SwapByReference, test2) {
    CPPLib cpplib;
    float n1 = float(1.1);
    float n2 = float(0.0);
    cpplib.SwapByReference(n1, n2);
    EXPECT_EQ(float(1.1), n2);
    EXPECT_EQ(float(0.0), n1);
}
//-----------------------------------------------------------------------------
