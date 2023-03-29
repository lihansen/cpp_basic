#include "q.h"

#include <iostream>
#include <stack>
#include <vector>
// Implement each function of `q.h` here.
bool CPPLib::CheckValidExpression(const std::string & input){
    std::stack <char> brkt_stack = {};
    
    for (int i = 0; i < int(input.size()); i++)
    {
        char c = char(input[i]);
        if(c == '(' or  c =='[' or c=='{' ){
            brkt_stack.push(c);
        }
        if(c==')'){
            if (brkt_stack.top() != '(')return false;
            else{
                brkt_stack.pop();
            }
        }
        if (c==']'){
            if (brkt_stack.top() != '[') return false;
            else{
                brkt_stack.pop();
            }
        }
        if (c=='}'){
            if (brkt_stack.top() != '{') return false;
            else{
                brkt_stack.pop();
            }
        }
    }
    if (brkt_stack.empty()){
        return true;
    }else{
        return false;
    }
}

bool CPPLib::IsPalindrome(const std::string & input){
    for (int i = 0; i < int(input.size()/2); i++)
    {
        if (input[i] != input[input.size()-i-1]){
            return false;
        }
    }
    return true;
}

int CPPLib::OddChar(const std::string & input){
    
    for (int i = 0; i < int(input.size()); i++)
    {
        bool even = false;
        for (int j = 0; j < int(input.size()); j++)
        {
            if (j != i and input[j] == input[i] ){
                even = true;
                break;
            }
        }
        if (even == false){
            return i;
        }
        
    }
    return -1;
}