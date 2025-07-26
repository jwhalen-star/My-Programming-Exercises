// Create a program that simulates an office supplies order system. Display the menu, accept user input, and print a receipt.

// Description: Declares a new array to capture inputs. Switch statement to populate an array of structs.

#include <iostream> 
#include <string>
 
using namespace std;

const int SIZE = 10; 

struct itemType
{
    string itemName;
    double itemPrice;
};

void getData(itemType itemList[]);
void showMenu(itemType itemList[]);
void userInput(int selections[]);
void printReceipt(int selections[], itemType itemList[]);

int main()
{
    itemType itemList[SIZE];
    int selections[SIZE];

    getData(itemList);
    showMenu(itemList);
    userInput(selections);
    printReceipt(selections, itemList);

    return 0;
}

void getData(itemType itemList[]) {
    int i = 0;
    while (i < SIZE) {
        switch(i) {
            case 0:
                itemList[i].itemName = "Notebook";
                itemList[i].itemPrice = 2.15; 
                break;
            case 1:
                itemList[i].itemName = "Pen Pack";
                itemList[i].itemPrice = 3.40;
                break;
            case 2:
                itemList[i].itemName = "Highlighter Set";
                itemList[i].itemPrice = 4.99;
                break;
            case 3:
                itemList[i].itemName = "Sticky Notes";
                itemList[i].itemPrice = 1.99;
                break;
            case 4:
                itemList[i].itemName = "Stapler";
                itemList[i].itemPrice = 5.50;
                break;
            case 5:
                itemList[i].itemName = "Paper Clips";
                itemList[i].itemPrice = 0.89;
                break;
            case 6:
                itemList[i].itemName = "Eraser";
                itemList[i].itemPrice = 0.75;
                break;
            case 7:
                itemList[i].itemName = "Ruler";
                itemList[i].itemPrice = 1.25;
                break;
            case 8:
                itemList[i].itemName = "Glue Stick";
                itemList[i].itemPrice = 1.10;
                break;
            case 9:
                itemList[i].itemName = "Calculator";
                itemList[i].itemPrice = 12.99;
                break;
            default:
                itemList[i].itemName = "Unknown Item";
                itemList[i].itemPrice = 0.00;
                break;       
        }
        i++;
    }
}

void showMenu(itemType itemList[]) {
    cout << "Welcome to PaperWorks Stationery Shop" << endl;
    cout << "----Available Items----" << endl;
    int i = 0;
    while (i < SIZE) {
        cout << i + 1 << ": " << itemList[i].itemName << "\t$" << itemList[i].itemPrice << endl;
        i++;
    }
}    
    
void userInput(int selections[]) {
    string continueFlag = "Y"; 
    cout << "You can select up to 10 different items" << endl;
    cout << "Would you like to make a selection? Y/y (Yes), N/n (No): ";
    cin >> continueFlag;
    int i = 0;
    while ((continueFlag == "Y" || continueFlag == "y") && (i < SIZE)) {
        cout << "Enter item number: ";
        cin >> selections[i];
        cout << endl;
        i++;

        if (i < SIZE) {
            cout << "Select another item? Y/y (Yes), N/n (No): ";
            cin >> continueFlag;
        } else {
            cout << "Maximum of 10 selections reached." << endl;
        }
    }
    cout << endl;
}

void printReceipt(int selections[], itemType itemList[]) {
    cout << "Thank you for shopping at PaperWorks Stationery Shop" << endl;
    int i = 0;
    while (i < SIZE) {
        cout << itemList[selections[i]].itemName << "\t$" << itemList[selections[i]].itemPrice << endl;
        i++; 
    }
}
