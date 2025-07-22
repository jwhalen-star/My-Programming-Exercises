/* Prompt: Create a program that calculates an employee's take home pay.
  
   Description: Modular calculations. Main() outputs results of calculations.
*/ 

#include <iostream>

using namespace std;

const double STATE_TAX_MULT = 0.07;             // When declared globally, no need to pass const variables as parameters, or include as arguments when defining a function
const double FEDERAL_TAX_MULT = 0.22;
const double DEPENDENT_DEDUCTION_MULT = 0.03;

double calc_state_tax(double monthlyEarnings);
double calc_federal_tax(double monthlyEarnings);
double calc_dependent_deduction(double numDependents, int monthlyEarnings);
double calc_total_withholding(double stateTax, double federalTax);
double calc_take_home_pay(double monthlyEarnings, double totalWithholding, double dependentDeduction);


void print_pay_summary(double monthlyEarnings, double stateTax, double federalTax, double dependentDeduction, double totalWithholding, double takeHomePay);

int main()
{
   double monthly_earnings;
   int num_dependents;
   
   cout << "Please input monthly earnings: ";
   cin >> monthly_earnings;
   cout << endl;
   
   cout << "Please input number of dependents: ";
   cin >> num_dependents;

   double state_tax = calc_state_tax(monthly_earnings);
   double federal_tax = calc_federal_tax(monthly_earnings);
   double dependent_deduction = calc_dependent_deduction(num_dependents, monthly_earnings);
   double total_withholding = calc_total_withholding(state_tax, federal_tax);
   double take_home_pay = calc_take_home_pay(monthly_earnings, total_withholding, dependent_deduction);

   print_pay_summary(monthly_earnings, state_tax, federal_tax, dependent_deduction, total_withholding, take_home_pay);

   return 0;
}

void print_pay_summary(double monthlyEarnings, double stateTax, double federalTax, double dependentDeduction, double totalWithholding, double takeHomePay) {
   cout << "State Tax: $" << stateTax << endl;
   cout << "Federal Tax: $" << federalTax << endl;
   cout << "Dependents Deduction: $" << dependentDeduction << endl;
   cout << "Total Withholding: $" << totalWithholding << endl;
   cout << "Monthly Earnings: $" << monthlyEarnings << endl;
   cout << "Take-Home Pay: $" << takeHomePay << endl;
}

double calc_state_tax(double monthlyEarnings) {
   return STATE_TAX_MULT * monthlyEarnings;
}

double calc_federal_tax(double monthlyEarnings) {
   return FEDERAL_TAX_MULT * monthlyEarnings;
}

double calc_dependent_deduction(int numDependents, double monthlyEarnings) {
   return DEPENDENT_DEDUCTION_MULT * numDependents * monthlyEarnings;
}

double calc_total_withholding(double stateTax, double federalTax) {
   return stateTax + federalTax;
}

double calc_take_home_pay(double monthlyEarnings, double totalWithholding, double dependentDeduction) {
   return monthlyEarnings - totalWithholding + dependentDeduction;
}



