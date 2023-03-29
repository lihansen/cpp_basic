#include "q.h"

#include <iostream>
#include <vector>

// Concatenate two dynamic arrays.
// Example:
// array_1 = {1, 2}, size_1 = 2
// array_2 = {2, 3, 4}, size_12 = 3
// Output: {1, 2, 2, 3, 4}.
// Question 1: Why did we have to proved size_1, size_2 as an input?
// Question 2: How can we know the size of the output?
int* CPPLib::Concatenate(int* array_1, int size_1, int* array_2, int size_2) {
    if (size_1 == 0 || size_2==0){
        return nullptr;
    }
    int *p = new int[size_1 + size_2];
    for (int i = 0; i< size_1; i++){
        *p = array_1[i];
        p++;
    }
    for (int i = 0; i<size_2; i ++){
        *p = array_2[i];
        p++;
    }
    return (p-size_1-size_2);
}
//-----------------------------------------------------------------------------
// Concatenate two dynamic vectors.
// Example:
// vector_1 = {1, 2}
// vector_2 = {2, 3, 4}
// Output: {1, 2, 2, 3, 4}.
// Question 1: Why didn't we provide the sizes?
// Question 2: We have two functions with the name of Concatenate. Is this ok?
std::vector<int> CPPLib::Concatenate(std::vector<int>& vector_1,
                                     std::vector<int>& vector_2) {
                                         std::vector <int> res = {};
                                         for (auto e: vector_1){
                                             res.push_back(e);
                                         }
                                         for (auto e: vector_2){
                                             res.push_back(e);

                                         }
                                         return res;
                            
                                     }
//-----------------------------------------------------------------------------
