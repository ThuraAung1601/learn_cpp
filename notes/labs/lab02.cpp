#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

// No. 1
int longest(string &p1, string &p2) {
    return (p1.length() > p2.length()) ? p1.length() : p2.length();
}

// 1.1
void print_format1(char ch, string &p1, string &p2) {
    int place_holder = longest(p1, p2)+3;
    cout << setfill(ch) << ch << setw(place_holder) << ch << endl; 
    cout << ch << setfill(' ') << setw(place_holder) << ch << endl;
    cout << "* " << p1 << setw((place_holder-p1.length()-1)) << '*' << endl;
    cout << ch << setfill(' ') << setw(place_holder) << ch << endl;
    cout << setfill(ch) << ch << setw(place_holder) << ch << endl; 
    cout << ch << setfill(' ') << setw(place_holder) << ch << endl;
    cout << "* " << p2 << setw((place_holder-p2.length()-1)) << '*' << endl;
    cout << ch << setfill(' ') << setw(place_holder) << ch << endl;
    cout << setfill(ch) << ch << setw(place_holder) << ch << endl; 
}

// 1.2
void print_format2(char corner, char ceil, char wall, string &p1, string &p2) {
    int place_holder = longest(p1, p2)+3;
    cout << corner << setfill(ceil) << setw(place_holder) << corner << endl; 
    cout << wall << setfill(' ') << setw(place_holder) << wall << endl;
    cout << "* " << p1 << setw((place_holder-p1.length()-1)) << '*' << endl;
    cout << wall << setfill(' ') << setw(place_holder) << wall << endl;
    cout << corner << setfill(ceil) << setw(place_holder) << corner << endl; 
    cout << wall << setfill(' ') << setw(place_holder) << wall << endl;
    cout << "* " << p2 << setw((place_holder-p2.length()-1)) << '*' << endl;
    cout << wall << setfill(' ') << setw(place_holder) << wall << endl;
    cout << corner << setfill(ceil) << setw(place_holder) << corner << endl; 
}

// No 2
void triangle1(int &size) {
    for (int i=0; i < size; i++) {
         cout << setfill('*') << setw(i+1) << '*' << endl;
    }
}

void triangle2(int size) {
    for (int i=0; i < size; i++) {
         cout << setfill('*') << setw(size-i) << '*' << endl;
    }
}

int main() {
    // string p1, p2;
    // cout << "Enter Player 1 and Player 2 names: "; cin >> p1 >> p2;
    // print_format1('*', p1, p2);
    // print_format2('+', '-', '|', p1, p2);

    int size = 0;
    triangle1(size);
    size = 5;
    triangle1(size);

    cout << endl;

    triangle2(5);

    cout << endl; 

    size = 5;
    triangle1(size);
    triangle2(size-1);

    return 0;
}
