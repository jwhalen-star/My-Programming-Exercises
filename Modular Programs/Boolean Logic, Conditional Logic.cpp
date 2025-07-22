/* Prompt: Create a program that determines if a time entered by the user is valid.

   Description: Modular. Reference variables as arguments for hours_min_seconds_input function to return more
   than one value from the function. Global const variables. 
*/

#include <iostream>

using namespace std;

const int MIN_HOURS = 0, MAX_HOURS = 23;
const int MIN_MINUTES = 0, MAX_MINUTES = 59;
const int MIN_SECONDS = 0, MAX_SECONDS = 59;

void hours_min_seconds_input(int& hours, int& minutes, int& seconds);
bool time_is_valid(int hours, int minutes, int seconds);
void output_isValidTime_function(bool is_valid_time, int input_hours, int input_min, int input_seconds);

int main()
{ 
   int num_hours;
   int num_minutes;
   int num_seconds;

   hours_min_seconds_input(num_hours, num_minutes, num_seconds);

   bool is_valid = time_is_valid(num_hours, num_minutes, num_seconds);

   output_isValidTime_function(is_valid, num_hours, num_minutes, num_seconds);

   return 0;
}

void hours_min_seconds_input(int& hours, int& minutes, int& seconds) {     // Uses reference variables to return more than one value
   cout << "Please input hours, minutes and seconds: " << endl;
   cin >> hours >> minutes >> seconds;
}

bool time_is_valid(int hours, int minutes, int seconds) {
   bool validTime;
   if (hours < MIN_HOURS || hours > MAX_HOURS) {  
      validTime = false;
      return validTime;
   } else if (minutes < MIN_MINUTES || minutes > MAX_MINUTES) {
      validTime = false;
      return validTime;
   } else if (seconds < MIN_SECONDS || seconds > MAX_SECONDS) { 
      validTime = false;
      return validTime;
   } else {
      validTime = true;
      return validTime;
   }
}

void output_isValidTime_function(bool is_valid_time, int input_hours, int input_min, int input_seconds) {
   if (is_valid_time) {
      cout << input_hours << ":" << input_min << ":" << input_seconds << " is a valid time." << endl;
   } else {
      cout << input_hours << ":" << input_min << ":" << input_seconds << " is an invalid time." << endl;
   }
}
