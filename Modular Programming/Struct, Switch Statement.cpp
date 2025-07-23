// Prompt: Create a program that calculates a freelancer's yearly bonus based on client satisfaction rating.

// Description: Uses a function to create and return a struct object. Switch statement within a function to return a yearly bonus.

#include <iostream>
#include <string>

using namespace std;

const double BONUS_HIGH = 0.30;
const double BONUS_MEDIUM = 0.18;
const double BONUS_LOW = 0.08; 
const double NO_BONUS = 0.00;

const int RATING_HIGH = 1;
const int RATING_MEDIUM = 2;
const int RATING_LOW = 3; 

struct Freelancer {
   string freelancerFirstName; 
   string freelancerLastName; 
   double yearlyEarnings;	
   int satisfactionRating; 
};

Freelancer getFreelancerData();
double bonusAmount(int satisfactionRating, double yearlyEarnings);

int main()
{
   Freelancer f = getFreelancerData();

   double bonusAmount = bonusAmount(f.satisfactionRating, f.yearlyEarnings);

   cout << "Freelancer Name: " << f.freelancerFirstName << " " << f.freelancerLastName << endl;
   cout << "Yearly Earnings: $" << f.yearlyEarnings << endl;
   cout << "Satisfaction Rating: " << f.satisfactionRating << endl;
   cout << "Yearly Bonus: $" << bonusAmount << endl;
   
   return 0;
}

Freelancer getFreelancerData() {
   Freelancer freelancerObject;

   cout << "Enter freelancer's first name: ";
   cin >> freelancerObject.freelancerFirstName;
   cout << "Enter freelancer's last name: ";
   cin >> freelancerObject.freelancerLastName;
   cout << "Enter freelancer's yearly earnings: ";
   cin >> freelancerObject.yearlyEarnings;
   cout << "Enter client satisfaction rating (1-3): ";
   cin >> freelancerObject.satisfactionRating; 

   return freelancerObject;
}

double bonusAmount(int satisfactionRating, double yearlyEarnings) {
   double calculatedBonus;

   switch(satisfactionRating)
   {
      case RATING_HIGH: 
         calculatedBonus = BONUS_HIGH * yearlyEarnings;
         break;
      case RATING_MEDIUM: 
         calculatedBonus = BONUS_MEDIUM * yearlyEarnings;
         break;
      case RATING_LOW: 
         calculatedBonus = BONUS_LOW * yearlyEarnings;
         break;
      default: 
         calculatedBonus = NO_BONUS;
         break;
   }

   return calculatedBonus;
}


