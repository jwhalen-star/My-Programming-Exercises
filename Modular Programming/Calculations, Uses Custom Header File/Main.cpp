// Prompt: Create a program that calculates prices for personalized mugs.

// Description: Int, string, and const data types, conditional logic, calculates total charges based on mug features.
// Also uses the an input validation module I've created and saved on my github

#include <iostream>
#include <string>
#include "InputValidation.h"

using namespace std;

const int BASE_CHARGE = 20;

string inputColor();
int calculateColorCharge(string color);
string inputMugType();
int calculateMugCharge(string mugType);
int inputNumWords();
int num_words_charge(int numWords);

int main()
{
   string mugType = inputMugType();
   int mugCharge = calculateMugCharge(mugType);
   string color = inputColor();
   int colorCharge = calculateColorCharge(color);
   int numOfWords = inputNumWords();
   int numWordsCharge = num_words_charge(numOfWords);

   double totalCharge = BASE_CHARGE + mugCharge + colorCharge + numWordsCharge;

   cout << fixed << showpoint << setprecision(2) << "The charge for this mug is $" << totalCharge << endl;

   return 0;
} 

string inputColor() {
   string color;

   cout << "Please choose what color you would like your mug to be: ";

   getline(cin, color);

   int i = 0;
   while (i < color.length()) {
      color[i] = tolower(color[i]);
      i++;
   }

   return color;
}

int calculateColorCharge(string color) {
   int color_charge;

   if (color == "red") {
      color_charge = 7;
   } else {
      color_charge = 3;
   }

   return color_charge;
}

string inputMugType() {
   string mugType;

   cout << "Please choose what type of mug you would like: ";

   getline(cin >> ws, mugType);                                // cin >> ws to account for newline character after input from previous function

   int i = 0;                                            // while loop to convert characters in string to lowercase
   while (i < mugType.length()) {
      mugType[i] = tolower(mugType[i]);
      i++;
   }

   return mugType;
}

int calculateMugCharge(string mugType) {
   int mugCharge;
   if (mugType == "ceramic") {
         mugCharge = 10;
      } else {
         mugCharge = 5;
   }

   return mugCharge;
}

int inputNumWords() {      // Uses input validation module from my github
   int numWords;

   cout << "Please decide how many words you would like on your mug: ";
   
   while (!isInteger(numWords)) {
      cout << "Invalid input. Please enter a whole number: ";
   }

   return numWords;
}

int num_words_charge(int numWords) {
   int numberOfWordsCharge = 0;
   
   if (numWords > 2) {
      numberOfWordsCharge = (numWords - 2) * 3;
   }

   return numberOfWordsCharge;
}