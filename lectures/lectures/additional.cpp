#include "lec9.h"
#include <iostream>

using namespace std;

// How to run:
// g++ -std=c++11 -o a lectures/additional.cpp lectures/lecture_9.cpp 

int main() {
    Student s1("Thura", 21, Grade::A);
    cout << s1.getAge() << endl;
    (s1.getGrade() == Grade::A) ? cout << "A" : cout << "B";
    return 0;
}