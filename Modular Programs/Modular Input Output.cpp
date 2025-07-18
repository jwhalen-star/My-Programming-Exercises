// Prompt: Create a program that asks a user for a simple output message. 

// Description: Uses basic cout and user input with getline. 

#include <iostream>
#include <string>

using namespace std;

string accept_user_input();
void output_user_input(string userOutput);

int main()
{
   string output_string = accept_user_input();

   output_user_input(output_string);
   
   return 0;
}

string accept_user_input() {
   string user_input_string;
   cout << "Please enter a string you would like the program to repeat back to you: ";
   getline(cin, user_input_string);
   cout << endl;
   return user_input_string;
}
void output_user_input(string userOutput) {
   cout << userOutput << endl;
}