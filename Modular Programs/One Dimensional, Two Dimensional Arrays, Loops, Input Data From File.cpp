// Calculate_Employee_Data.cpp : This file contains the 'main' function. Program execution begins and ends there.

// Name: Jordan Whalen
// Date: 07/21/2025
// Description: Populates arrays from data in a file, performs calculations. Outputs calculations and employee information.

#include <iostream>
#include <iomanip>
#include <fstream>      // fstream (file input output) library

using namespace std;

const int ROWS = 10;        // Global const variables
const int COLS = 3;

void getData(ifstream& inf, string n[], double emp[][COLS]);        // Prototypes
void calculateSalary(double emp[][COLS]);
void printEmpData(string n[], double emp[][COLS]);
double calculateAvgSalary(double emp[][COLS]);
void printEmpSalaryGreaterThanAvg(double avgSalary, string n[], double emp[][COLS]);

int main() {

    string names[ROWS];                 // Declaring first array
    double empData[ROWS][COLS];         // Declaring two dimensional array
    ifstream infile;                    // ifstream is data type (class). Creates file input object 'infile'
    infile.open("C:\\Users\\jordp\\OneDrive\\Desktop\\EmployeeSalary.dat");  // Opens input file

    /* Check if the input file exist.
    If the input file does not exist display "Cannot open input file. The program terminates."
    */

    if (!infile)
    {
        cout << "Cannot open input file. The program terminates." << endl;
        return 1;
    }

    cout << fixed << showpoint << setprecision(2);          // Output stream manipulators

    getData(infile, names, empData);                        // Function calls
    calculateSalary(empData);
    printEmpData(names, empData);

    double averageSalary = calculateAvgSalary(empData);

    cout << "Average Salary: $" << averageSalary << endl;
    cout << endl;

    cout << "Salary Greater than Avg: " << endl;

    printEmpSalaryGreaterThanAvg(averageSalary, names, empData);

    return 0;
}

/* Function Description: Pass input file stream object by reference (copying a stream is not allowed). Pass string array,
two dimensional array. Outer loop populates string array with 'name'. Inner loop populates two dimensional double array.
I used While loops. The inner loop resets the value of j with each iteration of the outer loop. The name, which is the first
item in each row of the input file is pulled first and populates the first array, and then the two numbers afterwards in
the same row are pulled next and populate the two dimmensional array.
Then the function iterates to the next row in the input data, and repeats.
*/
void getData(ifstream& inf, string n[], double emp[][COLS])
{
    int i = 0;
    while (i < ROWS) {
        inf >> n[i];
        int j = 0;                      // j reset to 0 each time outter loop runs
        while (j < COLS - 1) {          // innter loop runs for j = 0, j = 1
            inf >> emp[i][j];
            j++;
        }
        emp[i][2] = 0;                  // Third column, acting as a placeholder (because prompt sets COLS to 3), initializing to 0 for each row.
        i++;
    }
}

//Function Description: Passes the two dimensional array to perform salary calculations. Total salary with overtime pay saved in third column of array.
void calculateSalary(double emp[][COLS])   // To pass a two dimensional array, a function needs to know length of rows to allocate memory.
{
    int i = 0;
    while (i < ROWS) {
        if (emp[i][0] > 40) {
            emp[i][2] = (emp[i][0] - 40) * (emp[i][1] * 1.5) + (40 * emp[i][1]);
        }
        else {
            emp[i][2] = emp[i][0] * emp[i][1];
        }
        i++;
    }
}

//Function Description: Outputs the info from the two arrays into a readable format with a header into the terminal.
void printEmpData(string n[], double emp[][COLS])
{
    cout << "Name\t\tHrs Worked\tPay Rate\tSalary" << endl;
    int i = 0;
    while (i < ROWS) {
        cout << n[i] << "\t\t" << emp[i][0] << "\t\t" << emp[i][1] << "\t\t" << emp[i][2] << endl;
        i++;
    }
    cout << endl;
}

//Function Description: Calculates average salary using the figures in the third column calculated in the calculateSalary function.
double calculateAvgSalary(double emp[][COLS])
{
    double sum = 0;
    int i = 0;
    while (i < ROWS) {
        sum = sum + emp[i][2];
        i++;
    }
    return sum / ROWS;
}

//Function Description: Prints the name of an employee if the employee's salary is greater than the average.
void printEmpSalaryGreaterThanAvg(double averageSalary, string n[], double emp[][COLS])
{
    int i = 0;
    while (i < ROWS) {
        if (emp[i][2] >= averageSalary) {
            cout << n[i] << endl;
        }
        i++;
    }
}
