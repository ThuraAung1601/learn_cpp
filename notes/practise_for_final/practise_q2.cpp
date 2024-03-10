// Create a class representing a book with attributes 
// such as title, author, and publication year. 
// Implement both explicit and implicit constructors for this class. 
// Test your constructors by creating instances of the book class using both methods.

#include <iostream>
using namespace std;

class Book {
    public:
        string title, author; int year;
        explicit Book(string t, string a, int y) {
            title = t; author = a; year = y;
        }
        ~Book() {}
};

int main() {
    // error 
    // = means implicitly initialized
    // Book b1 = {
    //     "Hello", "John", 2024
    // };

    Book b2 {
        "Hello", "John", 2024
    };

    Book b3 (
        "Hello", "John", 2024
    );

    // cout << b1.title << endl;
    cout << b2.title << endl;
    cout << b3.title << endl;
    return 0;
}