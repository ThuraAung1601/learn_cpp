## Table of Content
- [Lecture 1](#Lecture-1-Introduction)
- [Lecture 2](#Lecture-2-Cpp-Structure)

## Lecture 1 Introduction

### Why C++
- Performance
- Control over system resources / low-level operations
- Object Oriented Programming

### OOP
- Object: an instance of a class
- Benefit
  - Re-usability
  - More natural way

- Class: Description of Object OR Blueprint for creating objects
  - Attributes => fields (variables) and methods

- Principles of OOP
  - Abstraction: Hiding complex reality by ***modeling classes appropriate to the problem***.
  - Encapsulation: ***Bundling the data and the methods that operate on the data*** into a single unit or class.
  - Inheritance: Mechanism where ***one class acquires the properties (methods and fields) of another***.
  - Polymorphism: Ability of different classes to be ***treated as instances of the same class through inheritance***.
    (To allow a single function or method to work in different ways depending on the object it is called on.)

- Why OOP ?
  - Limitation of procedural languages
    - Division into functions: grouping number of functions => large programs
    - Complex: Large programs become complex and difficult to debug
    - Data undervalued: Data is not secure because any function can access the global variable and change its values.
  - Reusable and easy to modify existing codes => No big programs
  - Single unit (objects) & functions inside the class (methods) - call the method in the object to use => No complex
  - Cannot access the data directly, only from reading data item in an object and return its value (encapsulation) => Data is secure.
 
  ```
  #include <iostream>
  using namespace std;

  // this is a comment
  /* this is multiline
    comment */
  
  int main() {
    cout << "Hello world" << endl;
    return 0;
  }
  ```

  ### Two types of Errors
  Syntax Error
  - Compile-time error
  - violating the C++ lang rules
  - fixing the syntax (from top to bottom)

  Logic Error
  - Run-time error
  - Program don't do what suppose to do

  Overflow Error
  - Round-off error
  - Computation result is outside of numeric range

  ### Fixing Errors
  - Testing: Validating program correctness
  - Debugging: Finding error source

  ### cout and cin
  ```
  #include <iostream>
  using namespace std;

  int main() {
    string name; int age;
    cout << "Enter your name: "; cin >> name;
    cout << "Enter your age: "; cin >> age;
    cout << name << " is " << age << " years old." << endl;
    return 0;
  }
  ```

  ```
  #include <iostream>
  #include <string>
  using namespace std;
  
  int main() {
    string name; int age;
    cout << "Enter your name: "; cin >> name;
    cout << "Enter your age: "; cin >> age;
    cout << name << " is " << age << " years old." << endl;
  
    // framing * around name
    const string greeting = "Hello " + name + "!";
    const string spaces(greeting.size(), ' ');
  
    const string second = "* " + spaces + " *";
    const string first(second.size(), '*');
  
    cout << first << endl;
    cout << second << endl;
    cout << "* " << greeting << " *" << endl;
    cout << second << endl;
    cout << first << endl;
  
    return 0;
  }
  ```

- string: #include<string>
// it will create 5 blank spaces by default
- setw(5): #include<iomanip>
// after this all will fill that * character
- setfill('*')
// setprecision(n): precision of n number
- scientific: will show in scifi format

```
  cout << setw(5) << 123 << setw(10) << 456 << endl;
  cout << setfill('*');
  cout << setw(5) << 123 << setw(10) << 456 << endl;
  double num = 3.14192436;
  cout << setprecision(1) << num << endl;
  // will take 3 digit
  cout << setprecision(3) << num << endl;
  cout << scientific << num << endl;
  // precision is 10: other values become zeros
  cout << setprecision(10) << fixed << num << endl;
```

Output is ...
```
%./no1              
      123       456
    **123*******456
    3
    3.14
    3.142e+00
    3.1419243600
```

- hex
- oct
- showbase
- noshowbase
- showpos
- noshowpos
- showpoint
- noshowpoint
- boolalpha
- noboolalpha
- uppercase
  
## Lecture 2 Cpp Structure
