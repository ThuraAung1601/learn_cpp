#include <iostream>
using namespace std;

// pass by reference
void swap(int& x, int& y) {
    int temp = x;
    x = y;
    y = temp;
}

int main() {
    int x = 5;
    int* y = &x;
    // address
    // cout << y << endl;
    // value
    // cout << *y << endl;
    // pointer y updates means x updates
    *y *= 2;
    // cout << x << endl;
   
    int num1 = 1; int num2 = 2;
    swap(num1, num2);
    // cout << num1 << "\t" << num2 << endl;

    int& num3 = num1;
    cout << num1 << endl;
    num3 *= 2;
    cout << num1 << "\t" << num3 << endl;

    int arr[] = {10, 20, 30};
    int* ptr = arr;
    cout << *ptr << endl;
    cout << *ptr+1 << endl;
    cout << arr[0] << endl;
    // moves to next index
    cout << *(ptr+1) << endl;

    int* ptr1 = &arr[1];
    int* ptr2 = &arr[2];
    // index difference (here 1 - 0)
    cout << ptr2 - ptr1 << endl; 

    char* str[]{"hello world", "hi"}; // not allowed char* str[] = "abc";
    cout << str[1] << endl;
    return 0;
}