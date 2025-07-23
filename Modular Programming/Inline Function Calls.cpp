/* Prompt: Create a program that calculates price to buy for a clothing store item. 
   
   Description: Inline function call. 
*/ 

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void get_item_name();
double get_retail_price();
double get_sale_percent();
double calc_sale_to_decimal(double postedSale);
double calc_price_to_buy(double retailPrice, double decimalSaleAmount);

int main()
{  
   get_item_name();

   cout << fixed << setprecision(2);
   cout << "The item costs: " << calc_price_to_buy(get_retail_price(), calc_sale_to_decimal(get_sale_percent()));
   
   return 0;
}
void get_item_name() {                 // Void functions implicitly return
   string name_of_item;
   cin.ignore();
   cout << "Please enter the name of the item: ";
   getline(cin, name_of_item);
   cout << endl;
   cout << "Your item is : " << name_of_item;
   cout << endl;
}
double get_retail_price() {
   double price_of_object_retail;
   cout << "Please enter the retail price of the object: ";
   cin >> price_of_object_retail;
   cout << endl;
   return price_of_object_retail;
}
double get_sale_percent() {
   double sale_amount;
   cout << "Please enter amount of sale: ";
   cin >> sale_amount;
   cout << endl;
   return sale_amount;
}   
double calc_sale_to_decimal(double postedSale) {      // Double because if int, integer division would result in '0'
   return postedSale / 100;
}
double calc_price_to_buy(double retailPrice, double decimalSaleAmount) {
   return retailPrice - (retailPrice * decimalSaleAmount);
}




