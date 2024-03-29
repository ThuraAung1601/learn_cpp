// Recursion problems for string

#include <iostream>
#include <string>
using namespace std;

// reverse string
string reverse_str(string input) {
    if (input.size() == 0 || input.size() == 1) {
        return input;
    }
    return reverse_str(input.substr(1, input.size())) + input[0];
}

// palindrome
bool palindrome(string input) {
    if (input.size() == 0 || input.size() == 1) {
        return true;
    } 
    if (input[0] == input[input.size()-1]) {
        return palindrome(input.substr(1, input.size()-2));
    }
    return false;
}

// is_substring
bool is_substr(string input, string sub) {
    if (sub.size() == 0 || input.substr(0, sub.size()) == sub) {
        return true;
    }
    if (input.size() == 0 || input.size() < sub.size()) {
        return false;
    }
    return is_substr(input.substr(1), sub);
}

// decimal to binary
string binary_converter(int num, string result="0") {
    if (num == 0) {
        return result;
    }
    int dividend = num / 2;
    int reminder = num % 2;
    return binary_converter(dividend, result + to_string(reminder));
}

int main() {
    string test = "software";
    cout << reverse_str(test) << endl;
    cout << palindrome("racecar") << endl;
    cout << palindrome(test) << endl;

    string test1 = "Hello world";
    string sub = test1.substr(0, 2);
    cout << test1 << " " << sub << endl;
    cout << is_substr(test1, sub);
    return 0;
}
