/* Prompt: Create a program that calculates your pet's age in any given year.
   
   Description: new_age_function handles output and loops until a valid year is entered.
   No need for return statements within the conditionals because the function ends after the loop exits.
   Return is implicit in void functions.
   Loop is sentinel controlled in that loop runs until valid input is received. 
*/

#include <iostream>

using namespace std;

void new_age_function(int petCurrentAge, int currentYear, int inputYear);

int main()
{
   int pet_current_age;
   int current_year;
   int input_year;
   int new_age;


   cout << "Please enter your pet's current age, the current year, and a year that you are wondering what " 
           "your pet's age will be (or was), separated by spaces: ";

   cin >> pet_current_age >> current_year >> input_year;
   cout << endl; 

   new_age_function(pet_current_age, current_year, input_year);
   
   return 0;
}

void new_age_function(int petCurrentAge, int currentYear, int inputYear) {
   while(true) {
      if (inputYear < (currentYear - petCurrentAge)) {
         cout << "Your pet was not born yet! Please enter another year: " << endl;
         cin >> inputYear;
      } else if (inputYear < currentYear) { 
         int pet_age = inputYear - (currentYear - petCurrentAge);     //pet_age variable declared in narrowest scope it is needed   
         cout << "Your pet was " << pet_age << " years old." << endl;
         break;
      } else if (inputYear == currentYear) {
         cout << "Your pet is " << petCurrentAge << " years old." << endl;
         break;
      } else {
         int pet_age = inputYear - (currentYear - petCurrentAge);       
         cout << "Your pet will be " << pet_age << " years old." << endl;
         break;
      }
    }
}


