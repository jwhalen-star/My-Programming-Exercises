// Create a program that prints a message for unavailable items on a restaurant menu.
// Description: Loops through modules in main. Sentinel value. Passes an array to a function.

#include <iostream>
#include <string>

using namespace std;

const int SIZE = 10;       // When an array is passed to a function, the function needs to know the size of an array. A function
                           // only receives a pointer to the first element of an array. Needs to be told the size.  
string getUserSelection();
bool isItemAvailable(string item, string menuItems[], int size);
void showAvailability(bool available);

int main() 
{
   string menu[SIZE] = {"Burger", "Salad", "Pizza", "Fries", "Wrap", "Taco", "Sushi", "Soup", "Pasta", "Steak"};

   while (true) {
      string selectedItem = getUserSelection();   

      if (selectedItem == "EXIT") {
         break;
      }

      bool itemFound = isItemAvailable(selectedItem, menu, SIZE);

      showAvailability(itemFound);
   }
	
   return 0;	
} 

string getUserSelection() {
   string itemName;
   cout << "Enter the name of a menu item (or type EXIT to quit): ";
   cin >> itemName;
   return itemName;
}

bool isItemAvailable(string item, string menuItems[], int size) {
   bool found = false;
   int index = 0;
   while (index < size) {
      if (item == menuItems[index]) {
         found = true;
         break;               // Terminates loop immediately if a match is found.
      }
      index++;
   }
   return found;   
}

void showAvailability(bool available) {
   if (available == true) {
      cout << "Item is on the menu." << endl;
   } else {
      cout << "Item not available." << endl;
   }      
}
