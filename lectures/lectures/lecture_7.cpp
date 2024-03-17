#include <iostream>
#include <iomanip>
#include <array>

#include <cstdlib>
#include <ctime>

#include <vector>
using namespace std;

#define SIZE 10

struct FreqDist {
    int element;
    int frequency;
};

int random_generator(int min, int max) {
    return min + rand() % (max - min + 1);
}

int counter(int arr[], int val) {
    int counter = 0;
    for (size_t i = 0; i < SIZE; i++) {
        if (arr[i] == val) {
            counter++;
        } 
    }
    return counter;
}

int main() {
    // const size_t SIZE = 50;
    array<int, SIZE> num_arr;
    num_arr = {
        1, 2, 3, 4, 5
    };

    // error 
    // int num_arr2[5];
    // num_arr2 = {
    //     1, 2, 3, 4, 5
    // };

    int num_arr2[SIZE] = {1, 2, 3, 4, 5};

    // cout << num_arr.size() << " " << sizeof(num_arr2)/sizeof(num_arr2[0]) << endl;

    // for (size_t i = 0; i < 5; i++) {
    //     cout << num_arr2[i] << ",";
    // }
    // cout << endl;

    unsigned int random_seed = static_cast<unsigned int>(time(nullptr));
    srand(random_seed);

    // for (size_t i = 0; i < 5; i++) {
    //     cout << random_generator(5, 50) << endl;
    // }

    for (size_t i = 5; i < SIZE; i++) {
        num_arr2[i] = random_generator(1, 10);
    }

    int num_arr3[SIZE];
    for (size_t i = 0; i < SIZE; i++) {
        num_arr3[i] = random_generator(5, 50);
    }

    // for (size_t i = 0; i < SIZE; i++) {
    //     cout << num_arr2[i] << ", ";
    // }

    // vector<FreqDist*> freq_list;

    // for (size_t i = 0; i < SIZE; i++) {
    //     FreqDist freq_dict1;
    //     freq_dict1.element = num_arr2[i];
    //     freq_dict1.frequency = counter(num_arr2, num_arr2[i]);
    //     cout << freq_dict1.element << "\t" << freq_dict1.frequency << endl;
    //     freq_list.push_back(&freq_dict1);
    // }

    // for  (size_t i = 0; i < SIZE; i++) {
    //     cout << freq_list[i]->element << "\t" << freq_list[i]-> frequency << endl;
    // }

    array<int, 5> arr1 = {1, 2, 3, 4, 5};
    // for (int i: arr1) {
    //     i++;
    // }

    // for (int i: arr1) {
    //     cout << i << endl;
    // }

    // cout << "Modified: " << endl;

    // for (int& i: arr1) {
    //     i++;
    // }

    // for (int i: arr1) {
    //     cout << i << endl;
    // }
    
    return 0;
}