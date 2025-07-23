// Description: Reusable header file for input validation. Validates input is an integer. 
// Include guard which prevents header file from being included more than once. Prevents redefinition errors.

#ifndef INPUTVALIDATION_H    // If "INPUTVALIDATION_H" has not been defined yet...
#define INPUTVALIDATION_H    // Defines "INPUTVALIDATION_H" symbol. The next time this header is included, #ifndef check will fail.

bool isInteger(int& inputInteger);  // Declaration of input validation function

#endif      // End of include guard


