/* Prompt: A school has 8 part-time tutors who log their weekly tutoring hours along with their hourly tutoring rate.
You are given a data file that contains the tutor's first name, the number of hours tutored in a week, and
their hourly tutoring rate. The program calculates each tutor's weekly earnings and the average earnings
among all tutors. It then outputs each tutor's weekly earnings, the average earnings, and the names of all
tutors earning less than or equal to the average. Tutors working more than 35 hours get 2x pay rate for hours
above 35. */

// Description: Populates arrays from data in a file, performs calculations. Outputs calculations and employee information.

#include <iostream>
#include <iomanip>
#include <fstream>      // fstream (file input output) library

using namespace std;

const int TUTORS = 8;        
const int DATA_COLS = 3;

void loadTutorData(ifstream& fin, string names[], double data[][DATA_COLS]);        // Prototypes
void computeEarnings(double data[][DATA_COLS]);
void displayTutorData(string names[], double data[][DATA_COLS]);
double computeAverageEarnings(double data[][DATA_COLS]);
void listTutorsBelowOrEqualAvg(double avgEarnings, string names[], double data[][DATA_COLS]);

int main() {

    string tutorNames[TUTORS];                 // Declaring one dimensional array
    double tutorData[TUTORS][DATA_COLS];      // Declaring two dimensional array
    ifstream infile;                          // ifstream data type (class). Creating file input object 'infile'.
    
    infile.open("TutorHours.dat");            // Opens input file

    /* Check if the input file exist.
    If the input file does not exist display "Cannot open input file. Program terminating." */

    if (!infile)
    {
        cout << "Cannot open input file. Program terminating." << endl;
        return 1;
    }

    cout << fixed << showpoint << setprecision(2);          // Output stream manipulators

    loadTutorData(infile, tutorNames, tutorData);                        
    computeEarnings(tutorData);
    displayTutorData(tutorNames, tutorData);

    double averageEarnings = computeAverageEarnings(tutorData);        // Value returned by computeAverageEarnings function saved to variable averageEarnings

    cout << "Average Weekly Earnings: $" << averageEarnings << endl;
    cout << endl;

    cout << "Tutors earning less than or equal to average:" << endl;

    listTutorsBelowOrEqualAvg(averageEarnings, tutorNames, tutorData);

    return 0;
}

/* Passes input file stream object by reference (copying a stream is not allowed). Passes string array,
two dimensional array. Outer loop populates string array with 'name'. Inner loop populates two dimensional array.
I used while loops. The inner loop resets the value of j with each iteration of the outer loop. The name, which is the first
item in each row of the input file is pulled first and populates the first array, and then the two numbers afterwards in
the same row are pulled next and populate the two dimensional array.
Then the function iterates to the next row in the input data, and repeats.*/

void loadTutorData(ifstream& fin, string names[], double data[][DATA_COLS])
{
    int i = 0;
    while (i < TUTORS) {
        fin >> names[i];
        int j = 0;                      // j reset to 0 each time outer loop runs
        while (j < DATA_COLS - 1) {     // inner loop runs for j = 0, j = 1
            fin >> data[i][j];
            j++;
        }
        data[i][2] = 0;                 // Third column, acting as a placeholder initializing to 0 for each row
        i++;
    }
}

// Passes the two dimensional array to perform earnings calculations. Total earnings with overtime pay saved in third column of array.
void computeEarnings(double data[][DATA_COLS])   // To pass a two dimensional array, a function needs to know length of rows to allocate memory.
{
    int i = 0;
    while (i < TUTORS) {
        if (data[i][0] > 35) {
            data[i][2] = (data[i][0] - 35) * (data[i][1] * 2.0) + (35 * data[i][1]);
        }
        else {
            data[i][2] = data[i][0] * data[i][1];
        }
        i++;
    }
}

// Outputs the info from the two arrays into a readable format with a header into the terminal.
void displayTutorData(string names[], double data[][DATA_COLS])
{
    cout << "Name\t\tHours Worked\tHourly Rate\tEarnings" << endl;
    int i = 0;
    while (i < TUTORS) {
        cout << names[i] << "\t\t" << data[i][0] << "\t\t" << data[i][1] << "\t\t" << data[i][2] << endl;
        i++;
    }
    cout << endl;
}

// Calculates average earnings using the figures in the third column calculated in the computeEarnings function.
double computeAverageEarnings(double data[][DATA_COLS])
{
    double sum = 0;
    int i = 0;
    while (i < TUTORS) {
        sum = sum + data[i][2];
        i++;
    }
    return sum / TUTORS;
}

// Prints the name of a tutor if the tutor's earnings is less than or equal to the average.
void listTutorsBelowOrEqualAvg(double avgEarnings, string names[], double data[][DATA_COLS])
{
    int i = 0;
    while (i < TUTORS) {
        if (data[i][2] <= avgEarnings) {
            cout << names[i] << endl;
        }
        i++;
    }
}
