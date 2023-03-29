#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write some test cases for each function.
//-----------------------------------------------------------------------------
TEST(MyTest, test_fib) {
    EXPECT_EQ(Fibonacci(-2), -1);
    EXPECT_EQ(Fibonacci(0), 0);
    EXPECT_EQ(Fibonacci(1), 1);
    EXPECT_EQ(Fibonacci(3), 3);
    EXPECT_EQ(Fibonacci(4), 5);
    EXPECT_EQ(Fibonacci(5), 8);
}


TEST(MyTest, test_CoinChangeMemo){

    std::vector <int> coins = {1,2,5};
    EXPECT_EQ(CoinChangeMemo(coins, 11), 3);
    EXPECT_EQ(CoinChangeTabulation(coins, 11), 3);

    std::vector <int> coins2 = {3,2,5};
    EXPECT_EQ(CoinChangeMemo(coins2, 10), 2);
    EXPECT_EQ(CoinChangeTabulation(coins2, 10), 2);

    std::vector <int> coins1 = {1};
    EXPECT_EQ(CoinChangeMemo(coins1, 1), 1);
    EXPECT_EQ(CoinChangeTabulation(coins, 1), 1);
}
