// Prompt: Create a program that calculates an employee's annual commission bonus.

// Description: Passes values by reference to enact changes on more than one variable at a time within a function. Conditional logic. Comparison operators. 

#include <iostream>
#include <string>

using namespace std;

const double BONUS_1 = 80.00;
const double BONUS_2 = 140.00;
const double BONUS_3 = 190.00; 
const double BONUS_4 = 320.00;

void getEmployeeInfo(string& employeeFirstName, string& employeeLastName, double& numClients, double& numMonths, double& totalSales);
double getBonus(double totalSales, double numClients, double numMonths);

int main()
{
   string employeeFirstName; 
   string employeeLastName;
   double numClients;
   double numMonths;
   double totalSales;

   getEmployeeInfo(employeeFirstName, employeeLastName, numClients, numMonths, totalSales);

   double bonus = getBonus(totalSales, numClients, numMonths);

   cout << "Employee Name: " << employeeFirstName << " " << employeeLastName << endl;
   cout << "Employee Bonus: $" << bonus << endl;
   
   return 0;
}

void getEmployeeInfo(string& employeeFirstName, string& employeeLastName, double& numClients, double& numMonths, double& totalSales) {
   cout << "Enter employee's first name: ";
   cin >> employeeFirstName;
   cout << "Enter employee's last name: ";
   cin >> employeeLastName;
   cout << "Enter number of months worked: ";
   cin >> numMonths;
   cout << "Enter number of clients handled: ";
   cin >> numClients; 
   cout << "Enter total sales made: ";
   cin >> totalSales; 
}

double getBonus(double totalSales, double numClients, double numMonths) {
   double bonus;

   if (totalSales / numClients / numMonths <= 60) {
      bonus = BONUS_1;
   } else if (totalSales / numClients / numMonths >= 61 && totalSales / numClients / numMonths <= 130) {
      bonus = BONUS_2;
   } else if (totalSales / numClients / numMonths >= 131 && totalSales / numClients / numMonths <= 270) {
      bonus = BONUS_3;
   } else if (totalSales / numClients / numMonths >= 271) {
      bonus = BONUS_4;
   }

   return bonus;
}