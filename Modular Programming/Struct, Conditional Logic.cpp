// Prompt: Develop a program that checks if a subway commuter qualifies for a 30% fare reduction based on their age.

// Description: Defines a struct to store commuter data. Uses a function to determine if the commuter qualifies for a discount.

#include <iostream>
#include <string>

using namespace std;

struct CommuterRecord {
   string givenName;
   string familyName;
   int yearsOld;
};

CommuterRecord inputCommuterData();
void checkDiscountEligibility(int age);

int main() 
{
   CommuterRecord rider = inputCommuterData();

   checkDiscountEligibility(rider.yearsOld);

   return 0;
} 

CommuterRecord inputCommuterData() {
   CommuterRecord record;

   cout << "Enter commuter's first name: ";
   cin >> record.givenName;
   cout << "Enter commuter's last name: ";
   cin >> record.familyName;
   cout << "Enter commuter's age: ";
   cin >> record.yearsOld;

   return record;
}

void checkDiscountEligibility(int age) {
   if (age <= 7 || age >= 62) {
      cout << "Commuter qualifies for a 30% fare reduction." << endl;
   } else {
      cout << "Commuter does not qualify for a fare reduction." << endl;
   }
}
