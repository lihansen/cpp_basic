#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write some test cases for each function.
//-----------------------------------------------------------------------------
TEST(Calculate, test1) { 
    CPPLib cpplib;
    int a = 2;
    int b = 3;
    auto res1 = cpplib.Calculate(a, b, Operation::add);
    auto res2 = cpplib.Calculate(a, b, Operation::subtract);
    auto res3 = cpplib.Calculate(a, b, Operation::division);
    auto res4 = cpplib.Calculate(a, b, Operation::multiplication);
    auto res5 = cpplib.Calculate(a, b, Operation::bitwise_AND);
    auto res6 = cpplib.Calculate(a, b, Operation::bitwise_OR);
    auto res7 = cpplib.Calculate(a, b, Operation::bitwise_XOR);
    auto res8 = cpplib.Calculate(a, b, Operation::shift_right);
    auto res9 = cpplib.Calculate(a, b, Operation::shift_left);

    
    EXPECT_EQ(res1, 5); 
    EXPECT_EQ(res2, -1); 
    EXPECT_EQ(res3, 0); 
    EXPECT_EQ(res4, 6); 
    EXPECT_EQ(res5, 2); 
    EXPECT_EQ(res6, 3); 
    EXPECT_EQ(res7, 1); 
    EXPECT_EQ(res8, 0);
    EXPECT_EQ(res9, 16);  
    
    }
//-----------------------------------------------------------------------------

TEST(Calculate, test2) {
        CPPLib cpplib;
    int a = -2;
    int b = 0;
    auto res1 = cpplib.Calculate(a, b, Operation::add);
    auto res2 = cpplib.Calculate(a, b, Operation::subtract);
    auto res3 = cpplib.Calculate(a, b, Operation::division);
    auto res4 = cpplib.Calculate(a, b, Operation::multiplication);
    auto res5 = cpplib.Calculate(a, b, Operation::bitwise_AND);
    auto res6 = cpplib.Calculate(a, b, Operation::bitwise_OR);
    auto res7 = cpplib.Calculate(a, b, Operation::bitwise_XOR);
    auto res8 = cpplib.Calculate(a, b, Operation::shift_right);
    auto res9 = cpplib.Calculate(a, b, Operation::shift_left);

    
    EXPECT_EQ(res1, -2); 
    EXPECT_EQ(res2, -2); 
    EXPECT_EQ(res3, float(FLT_MAX)); 
    EXPECT_EQ(res4, 0); 
    EXPECT_EQ(res5, 0); 
    EXPECT_EQ(res6, -2); 
    EXPECT_EQ(res7, -2); 
    EXPECT_EQ(res8, -2);
    EXPECT_EQ(res9, -2);  
}
//-----------------------------------------------------------------------------
