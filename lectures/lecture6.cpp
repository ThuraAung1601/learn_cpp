// lecture 6

#include<iostream>
#include<string>

// using class Dollar_amount from the header file DollarAmount.h
#include "DollarAmount.h"

// for setw
#include<iomanip>

// for random number generation
#include<cstdlib>

// for srand
// - srand takes an unsigned int and seeds the rand function to produce different
// -- random seq at each execution
#include<ctime>

using namespace std;

class Investor {
    struct Information {
        string name;
        long int amount;
    };
    Information info;
    public:
        void set_info(string name, long int amt) {
            info.name = name;
            info.amount = amt;
        }
        string get_name() {
            return info.name;
        }
        long int get_amount() {
            return info.amount;
        }
};

// function overloading
int maximum(int x, int y) {
    int max;
    if (x > y) {
        max = x;
    } else {
        max = y;
    }
    return max;
};

int maximum(int x, int y, int z) {
    int max = y;
    if (x > y) {
        max = x;
    } else {
        max = y; 
    }
    if (z > max) {
        max = z;
    }
    return max;
}

int main() {
    Investor A1;
    A1.set_info("John", 1000);
    cout << A1.get_amount() << endl;

    Dollar_amount d1(100); // Initializing d1 with an amount of 100 pennies
    cout << d1.toString() << endl;

    cout << maximum(100, 150) << endl;
    cout << maximum(100, 240, 20) << endl;

    // srand seed generation basd on current time
    // srand(static_cast<unsigned int>(time(0)));
    srand(time(NULL));

    // generate random number from range 1 to 6
    for (int counter = 1; counter <= 10; counter++) {
        cout << setw(10) << 1 + rand()%6;

        if (counter%5 == 0) {
            cout << endl;
        }
    }
}