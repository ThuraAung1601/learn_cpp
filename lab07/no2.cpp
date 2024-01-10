// no.2
// Write a C++ program that generates an array of 10 random integers between 1 and 100, 
// and then finds the maximum number in this array using a recursive func:on.

#include<iostream>
#include<ctime>
#include<stdio.h>
#include<array>
using namespace std;

int maxFindr(const int* ptr, size_t size) {
        if (size == 1) {
        return ptr[0];
    }
    // Find maximum in the rest of the array
    int maxRest = maxFindr(ptr + 1, size - 1); 
    // Compare the first element with the maximum of the rest
    return (ptr[0] > maxRest) ? ptr[0] : maxRest; 
}

void print_array(const int* ptr, size_t size) {
    if (size == 0) {
        return;
    }
    // Print the current element
    cout << *ptr << " ";
    // Move to the next element recursively
    print_array(ptr + 1, size - 1); 
}

int main() {
    const int SIZE = 10;
    int num_ls[SIZE];
    srand(static_cast<int>(time(NULL)));

    for (size_t i=0; i<SIZE; i++) {
        num_ls[i] = rand() % 100;
    }

    print_array(num_ls, SIZE);
    cout << endl;
    cout << maxFindr(num_ls, SIZE) << endl;
    return 0;
}
