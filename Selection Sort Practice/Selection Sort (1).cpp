/*
Write a C++ program that sorts the following product prices in descending order 
using the selection sort algorithm: 300, 800, 200, 900, 1000. 
After sorting, print the sorted list of prices separated by spaces.
*/


#include <iostream>
using namespace std;

const int num_prices = 5;

int product_prices[num_prices] = {300, 800, 200, 900, 1000};

void selection_sort(int list_prices[], int num_prices);

int main() {

    selection_sort(product_prices, num_prices);

    cout << "Sorted list: ";

    int i = 0;
    while (i < num_prices) {
        cout << product_prices[i] << " ";
        i++;
    }
    cout << endl;


    return 0;
}

void selection_sort(int list_prices[], int num_prices) {
    int i = 0;
    while (i < num_prices - 1) {
        int max_index = i;
        int j = i + 1;
        while(j < num_prices) {
            if (list_prices[j] > list_prices[max_index]) {
                max_index = j;
            }
            j++;
        }
        int temp = list_prices[i];
        list_prices[i] = list_prices[max_index];
        list_prices[max_index] = temp;

        i++;
    }
}

