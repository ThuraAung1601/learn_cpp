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
    - Overriding existing methods of existing classes.
    - To allow a single function or method to work in different ways depending on the object it is called on.)

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

### Programming Paradigms
- Imperative
  - Structured/Procedural
  - Object-oriented: Programs are composed of **Interrelated** objects
- Declarative
  - Functional
  - Logic

### Working with objects
- Strings: mutable types (name[0] = 'H' is valid.)
- Block or scope of variable { }
- Some objects can be used as variables.
  ```
  complex<double> a = 2; complex<double>=3i;
  a += b; // a is 2+3i
  ```

### auto
- auto: allows the compiler to automatically deduce the type of a variable from its initializer (like eval in Python?)
```
  int a[5] = {1, 2, 3, 4, 5};
  // auto will auto deduce each element of a is int
  // equivalent to for (int i: a) ...
  for (auto i: a) {
      cout << i << endl;
  };
```

### Data types
- Built-in / Primitive / Intrinsic types
- 9 types: char, short, int, long, bool, float, double, long long, long double
- int8_t: 8 bit integer

### Type Casting
```
  double x = 1.2;
  int y = x;
  cout << x << "'s integer is " << y << endl;
  //   double z = y; // error  
  
  double xx = 2.24;
  int yy = (int) xx;
  float zz = (float) (xx/yy);
  cout << xx << "'s integer is " << yy << " and divided value is " << zz << endl;
```
Output is ...
```
  1.2's integer is 1
  2.24's integer is 2 and divided value is 1.12
```

- static_cast<new type> ( expression ) (e.g static_cast<int> (3/2))
  - Identifies a cast at compile time
- dynamic_cast
  - Casting at runtime.
  - Only works on reference and pointers
- const_cast
  - cannot change their values
  - const_cast let the programmer to add or remove const keyword to ref or pointers
    (normally they cannot const)
- reinterpret_cast
  - Takes the bits in the expression and reuse them UNCONVERTED as a new type
  - Only works on reference and pointers

### Functions
- Pass by value: new variable, arguments are copied when used in function
- Pass by reference:
  - & is used, Not copied
  - compiler point the function that references the memory allocation (address) of the original variable
  - original value changes when reference variable changes (should consider using const if you don't want to update)
- Pass by pointers:
  - \* is used and also known as dereferencing. It accepts the value of the original variable.
  - it has own memory allocation

| Feature                  | Pass by Reference         | Pass by Pointer               |
|--------------------------|--------------------------|------------------------------|
| Syntax                   | `void functionName(Type &param)` | `void functionName(Type *param)` |
| Modification of Value    | Changes to the parameter inside the function affect the original value. | Changes to the dereferenced pointer inside the function affect the original value. |
| Nullability              | Not applicable. References must always be bound to valid objects. | Pointers can be assigned a `nullptr` or checked for null before dereferencing. |
| Initialization           | Must be initialized upon declaration. | Can be declared first and then initialized later. |
| Syntax for Calling       | `functionName(variable)` | `functionName(&variable)`      |
| Memory Overhead          | Generally lower as no extra memory is needed for a reference. | Requires additional memory to store the memory address. |
| Reference vs. Dereference | Direct use of the variable. | Requires dereferencing (`*pointer`) before using the value. |
| Pointer Arithmetic       | Not applicable. References do not support pointer arithmetic. | Allows for pointer arithmetic. |
| Ease of Use              | Easier syntax, often preferred for clarity. | Requires explicit dereferencing, which can be error-prone. |
| Pointer Ownership        | No ownership semantics. | Ownership can be transferred or managed explicitly. |
| Use in Arrays            | Cannot be used to iterate through an array. | Can be used with pointer arithmetic to iterate through an array. |

