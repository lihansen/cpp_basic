#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write some test cases for each function.
//-----------------------------------------------------------------------------
TEST(MyTest, Test1) {
    
    std::vector <int> values = {1,2,2,4,10};
    std::vector <int> weights = {1,2,1,12,4};
    int capacity = 15;
    EXPECT_EQ(knapSack01Tablulation(weights, values, capacity), 15);
    EXPECT_EQ(knapSack01Memo(weights, values, capacity), 15);
    EXPECT_EQ(knapSack01NoDynamicProgramming(weights, values, capacity), 15);
    
}

TEST(MyTest, Test2) {

    std::vector <int> values = {3,4,5,6};
    std::vector <int> weights = {2,3,4,5};
    int capacity = 8;
    EXPECT_EQ(knapSack01Tablulation(weights, values, capacity), 10);
    EXPECT_EQ(knapSack01Memo(weights, values, capacity), 10);
    EXPECT_EQ(knapSack01NoDynamicProgramming(weights, values, capacity), 10);
    
}
