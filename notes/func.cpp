#include<iostream>
#include<array>
#include<vector>
#include<string>
using namespace std;

// pass by value: original value is copied
void swap1(int n1, int n2) {
    int temp;
    temp = n1;
    n1 = n2;
    n2 = temp;
}

// pass by reference: original value is pointed
void swap2(int &n1, int &n2) {
    int temp;
    temp = n1;
    n1 = n2;
    n2 = temp;
}

// pass by pointer: address of the original variable is given
void swap3(int *n1, int *n2) {
    int temp;
    temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

template <typename T>
void swap4(T& a, T& b) {
    T temp;
    temp = a;
    a = b;
    b = a;
}

void printArray(int *ptr, size_t size) {
    if (size == 0) {
        cout << endl;
        return;
    }
    cout << *ptr << " ";
    // pointer is shifted to one position
    printArray(ptr+1, size-1);
}

void reverseArray(int *ptr, size_t size) {
    if (size == 0) {
        return;
    }
    reverseArray(ptr+1, size-1);
    cout << *ptr << " ";
}

void reverseVector(vector<int> vec, int size) {
    if (size == 0) {
        cout << vec[0] << endl;
        return;
    }
    cout << vec[size] << " ";
    reverseVector(vec, size-1);
}

int maxFinder(int *ptr, size_t size) {
    if (size == 1) {
        return ptr[0];
    }
    int max = maxFinder(ptr+1, size-1);
    return (ptr[0] > max) ? ptr[0] : max;
}

int main() {
    int a = 8;
    cout << &a << endl;
    int *ptr = &a;
    cout << *ptr << endl;

    // pass by value
    int n1 = 10; int n2 = 20;
    cout << n1 << '\t' << n2 << endl;
    swap1(n1, n2);
    cout << n1 << '\t' << n2 << endl;
    
    // pass by reference
    int n3 = 10; int n4 = 20;
    cout << n3 << '\t' << n4 << endl;
    swap2(n3, n4);
    cout << n3 << '\t' << n4 << endl;

    // pass by pointer
    int n5 = 10; int n6 = 20;
    cout << n5 << '\t' << n6 << endl;
    swap3(&n5, &n6);
    cout << n5 << '\t' << n6 << endl;

    // pass by reference with Generic
    int n7 = 10; int n8 = 20;
    cout << n7 << '\t' << n8 << endl;
    swap3(&n7, &n8);
    cout << n7 << '\t' << n8 << endl;

    int arr[4] = {10, 20, 30, 5};
    cout << *arr << endl;
    // pointer shifted by one position
    cout << *(arr+1) << endl;
    // invalid using ++ for shifting
    // cout << *arr++ << endl;
    
    // cannot use for CONTAINTER classes like vector, array, list
    // vector<int> vec = {10, 20, 30};
    // array<int, 3> arr2 = {10, 20, 30};
    // cout << *arr2 << endl;

    const size_t SIZE = sizeof(arr)/sizeof(arr[0]);
    printArray(arr, SIZE);
    cout << maxFinder(arr, SIZE) << endl;
    reverseArray(arr, SIZE);

    vector<int> vec = {11, 22, 33};
    for (int i: vec) {
        cout << i << " ";
    }
    cout << endl;
    reverseVector(vec, vec.size()-1);
    return 0;
}
