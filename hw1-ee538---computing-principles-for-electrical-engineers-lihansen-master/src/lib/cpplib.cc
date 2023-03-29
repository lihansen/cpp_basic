#include "cpplib.h"
#include "limits"
#include <iostream>
#include <string.h>

std::string CPPLib::PrintHelloWorld() { return "**** Hello World ****"; }

// NOTE: write your own function declaration q2 here
int CPPLib::FindAverage(std::vector<int> &input)
{
    if (input.size() == 0)
    {
        return -1;
    }
    else
    {
        int sum = 0;
        for (auto num : input)
        {
            sum += num;
        }
        return sum / input.size();
    }
}

// Question 5 Print your self-introduction
std::string CPPLib::PrintIntro()
{
    // Please fill up this function.
    std::string s = "name: Hansen Li \n"
                    "email: hansenli @usc.edu \n"
                    "major: ECE-Machine Learning and Data Science \n"
                    "hobby: coding.";

    return s;
}

// Question 6
std::vector<int> CPPLib::Flatten3DVector(const std::vector<std::vector<std::vector<int>>> &input)
{
    // Please fill up this function.
    std::vector<int> res;
    for (auto n1 : input)
    {
        for (auto n2 : n1)
        {
            for (auto n3 : n2)
            {
                res.push_back(n3);
            }
        }
    }

    return res;
}

// Question 7 Climbing Stairs
int CPPLib::climbStairs(int n)
{
    // Please fill up this function.
    if (n > 45)
        return -1;
    if (n <= 2){
        return n;
    }
    else{
        return climbStairs(n - 1) + climbStairs(n - 2);
    }

    // return 0;
}
