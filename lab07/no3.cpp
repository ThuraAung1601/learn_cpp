// no.3
// Write a C++ program that uses a recursive func:on to reverse a user-entered string.
#include<iostream>
#include<string>
using namespace std;

void print_reverse(string str, size_t index) {
    if (index <= 0) {
        cout << str[index] << endl;
        return;
    } 
    cout << str[index];
    print_reverse(str, index-1);
}

int main() {
    string input;
    cout << "Enter a string: "; getline(cin, input);
    print_reverse(input, input.size());
    return 0;
}
