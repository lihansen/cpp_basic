#include "q.h"

#include <iostream>
#include <list>
#include <stack>
#include <vector>
#include <unordered_map>
// Implement each function of `q.h` here.


// TODO: Implement the following functions in q.cc.

// Given a non-negative integer n, Implement a function that calculates the
// n(th) Fibonacci number.

// Your implementation should have a worst case runtime complexity of O(n) and
// memory complexity of O(1).
int Fibonacci(int n){
    if (n<0)return -1;
    if (n < 2) return n;
    int f_prev = 0;
    int f_curr = 1;
    while(n>0){
        int temp = f_curr;
        f_curr = f_prev + f_curr;
        f_prev = temp;
        n--;
    }
    return f_curr;
    
}

//-----------------------------------------------------------------------------
// Remember the Coin Change Problem:

// Given n different coin types and an integer representing the total amount of
// money, find the minimum number of coins to make up that amount. You can use
// as many coins as you want from each coin type.

// Example:
// Input: coins = [1, 2, 5], amount = 11
// Output: 3
//-----------------------------------------------------------------------------

// Implement a function that calculates the minimum number and use memoization
// but with a twist: you are only allowed to use an std::list for the memo (Do
// not use map, unordered_map, set, vector, or array).

// CoinChangeMemo is not a recursive function, but it is a wrapper around
// CoinChangeMemo_Helper that is recursive. Use std::list<int> for memo.
int CoinChangeMemo(std::vector<int>& coins, int amount){
    std::list <int> memo;
    for (int i = 0; i< amount + 1; i ++){
        memo.push_back(-1);
    }

    return CoinChangeMemo_Helper(coins, amount, memo);
}


int CoinChangeMemo_Helper(std::vector<int>& coins, int amount,
                           std::list <int>& memo){
    if (amount < 0 ) return -1;
    if (amount == 0) return 0;

    std::list<int>::iterator iter = memo.begin();
    for (int i = 0; i < amount; i++)
    {
        iter++;
    }

    if( *iter != -1){
        return *iter;
    }
    
    // this layer
    int min = INT32_MAX;
    for (auto coin:coins){
        int n = CoinChangeMemo_Helper(coins, amount-coin, memo);
        if (n >= 0){
            min = std::min(n, min);
        }
    }


    if (min >= 0 and min < INT32_MAX){
        *iter = 1 + min;
    }else{ 
        *iter = -1;
    }

    return *iter;
}


//-----------------------------------------------------------------------------
// Implement a function that calculates the minimum number and use tabulation
// but with a twist: you are only allowed to use an std::list for the table
// inside this function (Do not use map, unordered_map, set, vector, or array):

// int CoinChangeTabulation(std::vector<int>& coins, int amount){
//     std::vector <int> d(amount + 1);
//     d[0] = 0;

//     for (int i= 1; i<=amount; i++){
//         d[i] = INT32_MAX - 1;

//         for (auto coin : coins){
//             if (i - coin  >= 0){
//                 d[i] = std::min(d[i-coin] + 1, d[i]);
//             }
//         }
//     }
//     return  d[amount] > amount ? -1 : d[amount];
// }


int CoinChangeTabulation(std::vector<int>& coins, int amount){
    std::list <int> d;
    d.push_back(0);

    for (int i = 1; i< amount +1; i++){
        d.push_back(INT32_MAX - 1);
    }
   
    auto iter = d.begin(); //d[0] = 0
    for (int i= 1; i<=amount; i++){
    
        iter ++;

        for (auto coin : coins){
            if (i - coin  >= 0){
                auto iter_prev = d.begin();
                for (int j = 0; j < i-coin; j++){
                    iter_prev++;
                }
                // d[i] = std::min(d[i-coin] + 1, d[i]);
                
                *iter = std::min( (*iter_prev) + 1, *iter);
            }
        }
    }

    return *--d.end() > amount ? -1 : *--d.end();
}

