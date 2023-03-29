#include <string>

#include "q.h"

// A function that capitalize the first letter of a string.
// If it was possible, returns true, otherwise false.
bool CPPLib::CapitalizeFirstLetter(std::string &input) {
    if (input.size() == 0){
        return false;
    }
    int val = (int)(input[0]);
    if (val < 97 || val > 122){
        return false;
    }
    input[0] += 'A' - 'a';
    return true;
}
