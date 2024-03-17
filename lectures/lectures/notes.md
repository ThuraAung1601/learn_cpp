## Lecture 7

- random numbers
```
#include <cstdlib>
#include <ctime>

unsigned int random_seed = static_cast<unsigned int>(time(nullptr));
srand(random_seed);

int random_generator(int min, int max) {
    return min + rand() % (max - min + 1);
}
```

- static array does not reinitialize in second call - compile time
- dynamic array reinitialize in second call - runtime

```
static array<int, 3> arr1; // static
array<int, 3> arr2; // dynamic
```

- Using & (reference) in the iterator objects makes the original value changes
```
for (int& i: arr1) {
    i++;
}
```

## Lecture 8
Pointer = variable holds address of another variable
```
int x = 5;
int* y = &x;
// address
cout << y << endl;
// value
cout << *y << endl;
// pointer y updates means &x updates that makes x updates
*y *= 2;
cout << x << endl;

int num1;
// num3 is reference of num1
int& num3 = num1;
cout << num1 << endl;
//so num3 which is &num1 updates means num1 updates
num3 *= 2;
cout << num1 << "\t" << num3 << endl;
```

```
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
```

```
char* str[]{"hello world", "hi"}; // not allowed char* str[] = "abc";
cout << str[1] << endl; // hi
```

## Lecture 9
```
// How to run:
// g++ -std=c++11 -o a lectures/lecture_9.cpp main.cpp
```

```
// if class member and initializer variables are same names use this->
Student::Student(string name, int age, Grade grade) {
    this->name = name;
    this->age = age;
    this->grade = grade;
}
```

```
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
```

- Private members can be modified using & and * concepts
- Considerations: Encapsulation breach, Const correctness and Lift-time management

const keyword
```
// error
const Student s4("Thura", 21, Grade::A);
Student& s5 = s4; // Use const Student& s5 = s4;
s5.setAge(23); // Error if use const Student& s5 = s4; because of const
cout << "S3: " << s5.getAge() << endl;
cout << "S1: " << s4.getAge() << endl;

// error
Student* s5 = &s4; // Use const Student* s5 = &s4;
s5.setAge(23); // Error if use const Student& s5 = s4; because of const
cout << "S3: " << s5.getAge() << endl;
cout << "S1: " << s4.getAge() << endl;
```

Composition
- Using a class as a member of another class

## Lecture 10

Operator overloading unchanged
- Precedence 
- Associativity
- Arity 

Restrictions
- No new operator
- cannot alter fundamental types - int, char, etc.
- \+ and += do not automatically shared the overloading
- -> () [] = must be declared as member of the class.

See the code: https://github.com/ThuraAung1601/learn_cpp/tree/main/notes/practise_for_final/complex.cpp

Dynamic memory management
```
int* ptr = new int;
int* arr = new int[10];

delete ptr;
delete[] arr;
```

## Lecture 11

```
    // ios::app is to append the existing text file
    ofstream myFile("check_out_list.txt", ios::app);
    if (myFile.is_open()) {  // if(!myFile.fail())
        for(CheckOut i: checkout_list) {
            myFile << i << endl;
        }
    } else {
        cerr << "Error:: File cannot opened";
        exit(1);
    };

    if (myFile.is_open()) {  // if(!myFile.fail())
        myFile << no1 << endl;
    } else {
        cerr << "Error:: File cannot opened";
        exit(1);
    };

    myFile.close();

    // read from the file
    ifstream myFile1("check_out_list.txt");
    string line;
    while (getline(myFile1, line)) {
        cout << line << endl;
    }
    myFile1.close();
```

## Lecture 12
Polymorphism

See the code: https://github.com/ThuraAung1601/learn_cpp/blob/main/notes/practise_for_final/practise_q3.cpp

Runtime polymorphism
```
// Create objects of Circle and Rectangle
Circle circle(5);
Rectangle rectangle(4, 6);

// Pointer to the base class
Shape* shape1 = &circle;
Shape* shape2 = &rectangle;

// Calculate and print areas using runtime polymorphism
std::cout << "Area of Circle: " << shape1->area() << std::endl;
std::cout << "Area of Rectangle: " << shape2->area() << std::endl;
```