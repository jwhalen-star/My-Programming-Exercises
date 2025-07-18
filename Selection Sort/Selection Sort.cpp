/*
Prompt: Write a C++ program that sorts the following product prices in ascending order 
using a selection sort algorithm: 1200, 499, 2500, 799, 1500. 
After sorting, print the sorted list of prices separated by spaces.

Please note the modularity of the program. 'While' loop implementaton as opposed to 'for' loops
*/

#include <iostream>
using namespace std;

const int num_elements = 5;

int product_prices[num_elements] = {1200, 499, 2500, 799, 1500};

void selection_sort(int list_of_elements[], int num_elements);

int main() {

    selection_sort(product_prices, num_elements);

    cout << "Sorted list: ";

    int i = 0;
    while (i < num_elements) {
        cout << product_prices[i] << " ";
        i++;
    }
    cout << endl;

    return 0;
}

void selection_sort(int list_of_elements[], int num_elements) {
    int i = 0;
    while (i < num_elements - 1) {          // When i reaches last element, no need to sort further
        int min_index = i;
        int j = i + 1;
        while (j < num_elements) {          // Inner loop compares remaining elements to current element
            if (list_of_elements[j] < list_of_elements[min_index]) {
                min_index = j;
            }
            j++;
        }
        int temp = list_of_elements[i];         // Swap
        list_of_elements[i] = list_of_elements[min_index];
        list_of_elements[min_index] = temp;

        i++;
    }
}
