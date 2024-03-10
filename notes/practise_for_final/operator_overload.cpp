// operator overloading
#include <iostream>
using namespace std;

class People {
    private:
        string name; int age;
    public:
        People(string n, int a) {
            name = n; age = a;
        }

    friend ostream& operator<<(ostream& out, People& p1);   
};

class Book {
    private:
        string name; string author; double price;
    public:
        Book(string n, string a, double p) {
            name = n; author = a; price = p;
        }
    
    friend ostream& operator<<(ostream& out, Book& b1);
    
    double operator+ (Book& other) {
        return price + other.price;
    }
};

ostream& operator<<(ostream& out, People& p1) {
    out << p1.name << ", " << p1.age;
    return out;
}

ostream& operator<<(ostream& out, Book& b1) {
    out << b1.name << ", " << b1.author << ", " << b1.price;
    return out;
}

int main() {
    People p1 = {
        "Tun Tun", 
        15
    };
    cout << p1 << endl;

    Book b1("Hello", "John", 120);
    cout << b1 << endl;

    Book b2("Hell0", "Willy", 100);
    cout << b2 << endl;
    
    cout << b1+b2 << endl;
    return 0;
}