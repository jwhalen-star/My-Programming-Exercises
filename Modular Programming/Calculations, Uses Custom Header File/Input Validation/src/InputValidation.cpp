#include <iostream>
#include "InputValidation.h"

using namespace std;

bool isInteger(int& inputInteger) {
    if (cin >> inputInteger) {
        return true;
    } else {
        return false;
    }
}
