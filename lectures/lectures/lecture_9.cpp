#include "lec9.h"
#include <iostream>

using namespace std;

// if there are same names use this->
Student::Student(string name, int age, Grade grade) {
    this->name = name;
    this->age = age;
    this->grade = grade;
}

void Student::setAge(int age) {
    this->age = age;
}

int Student::getAge() const {
    return age;
}

Grade Student::getGrade() const {
    return grade;
}

int main() {
    Student s1("Thura", 21, Grade::A);
    cout << s1.getAge() << endl;
    (s1.getGrade() == Grade::A) ? cout << "A" << endl: cout << "B" << endl;

    // reference of the object can modify the value
    Student& s2 = s1;
    s2.setAge(22);
    cout << "S2: " << s2.getAge() << endl;
    cout << "S1: " << s1.getAge() << endl;

    // pointer to the object can modify the value
    Student* s3 = &s1;
    s3->setAge(23);
    cout << "S3: " << s3->getAge() << endl;
    cout << "S1: " << s1.getAge() << endl;

    // error
    // const Student s4("Thura", 21, Grade::A);
    // Student& s5 = s4; // Use const Student& s5 = s4;
    // s5.setAge(23); // Error if use const Student& s5 = s4; because of const
    // cout << "S3: " << s5.getAge() << endl;
    // cout << "S1: " << s4.getAge() << endl;

    // error
    // Student* s5 = &s4; // Use const Student* s5 = &s4;
    // s5.setAge(23); // Error if use const Student& s5 = s4; because of const
    // cout << "S3: " << s5.getAge() << endl;
    // cout << "S1: " << s4.getAge() << endl;
    return 0;
}