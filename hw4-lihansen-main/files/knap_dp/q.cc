#include "q.h"

#include <iostream>
#include <vector>
// Implement each function of `q.h` here.


// Given a vector of weights and values and an integer value representing total
// capacity of a knapsack, implement the following function.

// The knapSack01NoDynamicProgramming function does not use Dynamic Programming
// and it is not a recursive function. Instead it calls a recursive function
// knapSack01NoDynamicProgramming_Helper (which is also not using dynamic
// programming).

// 1. Implement knapSack01NoDynamicProgramming:
int knapSack01NoDynamicProgramming(const std::vector<int> &weights,
                                   const std::vector<int> &values, int w){
    return knapSack01NoDynamicProgramming_Helper(weights, values,  w, values.size()-1);
                                   }

// // 2. Define knapSack01NoDynamicProgramming_Helper and implement it in the .cc
// // file. This function has takes similar arguments like
// // knapSack01NoDynamicProgramming with some extra helper parameters:
int knapSack01NoDynamicProgramming_Helper(const std::vector<int> &weights, const std::vector<int> &values, int w, int i){
    if (i == -1 or w == 0) {
        return 0;
    }

    if (weights[i] > w) {
        return knapSack01NoDynamicProgramming_Helper(weights, values,  w, i - 1);
    }

    return std::max(
        knapSack01NoDynamicProgramming_Helper(weights, values, w, i - 1),
        values[i] + knapSack01NoDynamicProgramming_Helper(weights, values,  w - weights[i], i - 1)
    );

}


                                          

//-----------------------------------------------------------------------------
// 3. Implement knapSack01Memo:

// The knapSack01Memo function itself doesn't use a memo. It's just a wrapper
// around knapSack01Memo_Helper.
int knapSack01Memo(const std::vector<int> &weights, const std::vector<int> &values, int w){
    std::vector<std::vector<int>> memo (values.size(), std::vector <int>(w+1, -100));

    // return memo[0][1];
    return knapSack01Memo_Helper(weights, values, w, values.size()-1, memo);
}

// 4. Implement knapSack01Memo_Helper. This function has takes similar arguments
// like knapSack01Memo with some extra helper parameters such as i and memo,
// which is a two-dimensional vector:
int knapSack01Memo_Helper(const std::vector<int> &weights,
                          const std::vector<int> &values, int w, int i,
                          std::vector<std::vector<int>> &memo){
                            if (i == -1 || w == 0) {
                                return 0;
                            }
                            if (memo[i][w] != -100) {
                                return memo[i][w];
                            }
                            if (weights[i] > w) {
                                memo[i][w] = knapSack01Memo_Helper(weights, values, w, i - 1, memo);
                                return memo[i][w];
                            }

                            memo[i][w] = std::max(
                                knapSack01Memo_Helper(weights, values, w, i - 1,  memo),
                                values[i] + knapSack01Memo_Helper(weights, values,  w - weights[i], i - 1, memo)
                            );

                            return memo[i][w];
                          }


// //-----------------------------------------------------------------------------
// 3. Implement knapSack01Tablulation. Use a two-dimensional vector for the
// table.
int knapSack01Tablulation(const std::vector<int> &weights,
                          const std::vector<int> &values, int w){
                            std::vector<std::vector<int>> d(values.size() + 1, std::vector<int>(w + 1, 0));
                            for (int i=0; i<= int(weights.size()); i++){
                                for (int _w= 0; _w<= w; _w++){
                                    if(i == 0 or  _w == 0){
                                        d[i][_w] = 0;
                                    }else if(weights[i-1] > _w) {
                                        d[i][_w] = d[i-1][_w];
                                    }else{
                                        d[i][_w] = std::max(values[i-1] + d[i-1][_w - weights[i - 1]], d[i - 1][_w]);
                                    }
                                }
                            }
                            return d[values.size()][w];
                          }

// int main(){
//     std::cout<<"fuck";
// }