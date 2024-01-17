#include<iostream>
using namespace std;

void mystery1(char *, const char*);
void mystery2(char *, const char*);

int main() {
    char string1[20];
    char string2[20];

    // Test Case 1: Concatenate and print
    cout << "Enter two strings for mystery1: ";
    cin >> string1 >> string2;
    mystery1(string1, string2);
    cout << string1 << endl;

    // Test Case 2: Check if substring
    cout << "Enter two strings for mystery2: ";
    cin >> string1 >> string2;
    mystery2(string1, string2);

    // Test Case 3: Error case for mystery1
    // char errorString1[10] = "Hello";
    // char errorString2[15] = "World";
    // mystery1(errorString1, errorString2);

    return 0;
}

// // mystery1 concatenate string 1 and string 2 into string 1
// void mystery1(char *s1, const char *s2) {
//     while (*s1 != '\0') {
//         // pointer shift from the left to the right by one to the end (i.e. null terminator \0)
//         ++s1;
//     }
//     // no initialization; value from *s2 go to *s1 (i.e. concatenation); shift by one
//     // expressions inside conditions are considered true if their value is nonzero and false if their value is zero.
//     for (; (*s1=*s2); ++s1, ++s2) {
//         // concatenate the string2 until it get the end (i.e. null terminator \0)
//     }
// }

template <typename T>
size_t len(T *s) {
    size_t length;
    for (length = 0; *s != '\0'; ++s) {
        length++;
    }
    return length;
} 

// mystery1 concatenate string 1 and string 2 into string 1
void mystery1(char *s1, const char *s2) {
    size_t LIMIT = 20;
    size_t len_of_s1 = len(s1);
    size_t len_of_s2 = len(s2);

    if (len_of_s1+len_of_s2 <= LIMIT) {
        while (*s1 != '\0') {
            // pointer shift from the left to the right by one to the end (i.e. null terminator \0)
            ++s1;
        }
        // no initialization; value from *s2 go to *s1 (i.e. concatenation); shift by one
        for (; (*s1=*s2); ++s1, ++s2) {
            // concatenate the string2 until it get the end (i.e. null terminator \0)
        }
    } else {
        cout << "Error: Insufficient space for concatenation." << endl;
        *s1 = '\0';
        return;
    }
}

void mystery2(char *s1, const char *s2) {
    while (*s1 != '\0') {
            if (*s1 == *s2) {
                cout << "Yes" << endl;
                return;
            }
            s1++; s2++;
    }
    cout << "No" << endl;
}
