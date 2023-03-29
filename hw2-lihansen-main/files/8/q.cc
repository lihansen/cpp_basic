#include <iostream>
#include <vector>
#include <set>
#include "q.h"

// Write a function that takes a vector of positive integers as input. The
// output is the same vector where all duplicates are removed. Note that the
// output is the same vector means the function's return type should be void and
// do the modifications on the input vector. Example: before: v=[1, 2, 2, 4],
// after : v=[1, 2, 4] Solve this for the following cases: You cannot use
// std::set
void CPPLib::UniqueVectorNotBySet(std::vector<int> &input) {
    for (int i = 0; i < input.size(); i++)
    {
        /* code */
        for (int j = 0; j < input.size(); j++){
            if (j != i && input[j] == input[i]){
                input.erase(input.begin()+i);
            }
        }
    }
    
}
// You can use std::set
void CPPLib::UniqueVectorBySet(std::vector<int> &input) {
    std::set <int> unique;
    for (auto e: input){
        unique.insert(e);
    }
    input = std::vector <int> (unique.begin(),unique.end());

}

// Write a function that takes two vectors v1 and v2 and returns a new vector
// that is the intersection of the values in v1 and v2. All the values in return
// vector should be unique.
// Example: input: v1={1, 2, 2, 3}, v2={3, 4, 4, 5},
// output = {1, 2, 3, 4, 5}
std::vector<int> CPPLib::IntersectVectors(std::vector<int> &input1,
                                          std::vector<int> &input2) {
                                              std::set <int> s;
                                              for (auto e : input1){
                                                  s.insert(e);
                                              }
                                              for(auto e: input2){
                                                  s.insert(e);
                                              }
                                              return std::vector <int> (s.begin(), s.end());
                                          }
