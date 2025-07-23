// Prompt: Create a program that determines the highest and lowest temperatures recorded over three days.

// Description: Relational operators and conditional logic. Passes arrays to functions

#include <iostream>

using namespace std;

int findLowest(int inputList[]);
int findHighest(int inputList[]);

int main()
{	 
   int tempList[] = {72, 85, 68};       // Do not need to specify a size if initializing array right away

   int highest = findHighest(tempList);     // Calls come after declaring any variables passed as parameters
   int lowest = findLowest(tempList);

   cout << "The highest temperature is " << highest << endl;
   cout << "The lowest temperature is " << lowest << endl;
   
   return 0; 
}

int findLowest(int inputList[]) {            // Arrays passed to functions as pointer to the first element
    int lowest;

    if (inputList[0] < inputList[1]) {
      lowest = inputList[0];
   } else {
      lowest = inputList[1];
   }

   if (inputList[2] < lowest) {
      lowest = inputList[2];
   }

   return lowest;
}

int findHighest(int inputList[]) {
    int highest;

    if (inputList[0] > inputList[1]) {
      highest = inputList[0];
   } else {
      highest = inputList[1];
   }

   if (inputList[2] > highest) {
      highest = inputList[2];
   }

   return highest;
}