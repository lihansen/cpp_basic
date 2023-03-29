#include "q.h"

#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>
// Returns the index of the fist space character in a string.
int CPPLib::IndexOfFirstSpace(std::string& input) {
    for (int i = 0; i < input.size(); i++)
    {
        /* code */
        if (input[i] == ' '){
            return i;
        }
    }
    return -1;
}

// Given the full_name, it returns the first_name and last_name.
// Note: you should use IndexOfFirstSpace function and cannot use any other
// std:: functions.
void CPPLib::SeparateFirstAndLastNames(std::string& full_name,
                                       std::string& first_name,
                                       std::string& last_name) {
                                           int space_idx = CPPLib::IndexOfFirstSpace(full_name);
                                           first_name = full_name.substr(0, space_idx);
                                           last_name = full_name.substr(space_idx+1, full_name.size()-1);
                                       }

// Returns the number of vowles (a, e, i, o, u) in a string.
int CPPLib::NumberOfVowels(std::string& input) {
    int count = 0;
    std::unordered_set <char> vowles = {'a','e','i','o','u'};

    for (int i = 0; i < input.size(); i++)
    {
        /* code */
        auto got = vowles.find(input[i]);
        if (got != vowles.end()){
            count ++;
        }
    }
    return count;
    
}

// Returns the number of consonants (letters that are not a, e, i, o, u) in a
// string.
int CPPLib::NumberOfConsonants(std::string& input) {
    return input.size()-NumberOfVowels(input);
}

// Returns the revers of a string.
// Example input: 'ted', output: 'det'.
// Note: You cannot use any std:: functions.
int CPPLib::Reverse(std::string& input) {
    int n = input.size();
    // Swap character starting from two
    // corners
    for (int i = 0; i < n / 2; i++){
        char temp = input[i];
        input[i] = input[n-i-1];
        input[n-i-1] = temp;
    }
    return 0;

}
