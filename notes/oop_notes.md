## OOP Object Oriented Programming

### Objects
- attributes = characteristics of an object
- an attribute describes the current states
- a well-defined object - it has its own identity, attributes, and behavior.

### Classes
- Each class has a name and describes attributes and behavior (methods).
- Classes are blueprints of objects
- attributes are also referred to as properties or data.
- Process of creating object = instantiation

### Access specifiers
- public
- private: default specifier
- protected

### Abstraction
- abstraction is the concept of providing only essential information to the outside world
- allows us to write a single bank account class, and then create different objects based on the class, for individual bank accounts, rather than creating a separate class for each bank account.
- foundation for encapsulation and polymorphism
  
### Encapsulation
- data hiding
- restricting access to the inner workings of that class

### Constructors
- called when the class is created
```
class myClass {
  public:
    myClass(string nm) {
      setName(nm);
    }
    void setName(string x) {
      name = x;
    }
    string getName() {
      return name;
    }
  private:
    string name;
};

int main() {
  myClass ob1("David");
  myClass ob2("Amy");
  cout << ob1.getName();
}
```

### Headers Source
- Header: declare variables and functions
- Source: implementation
- #include headers

### Constructors and Destructors
- Constructor: run when the object is created
- Destructor: when deleted
  - cannot have the parameters
  - cannot overload
  - called when object is deleted

```
class MyClass
{
  public:
    // constructor
   MyClass();
    // destructor
   ~MyClass();
};;
```

### ifndef
```
#ifndef MYCLASS_H
#define MYCLASS_H

class MyClass
{
  public:
  MyClass();
  protected:
  private:
};

#endif // MYCLASS_H 
```
ifndef stands for "if not defined". The first pair of statements tells the program to define the MyClass header file if it has not been defined already.

endif ends the condition.

### Pointers and Classes

```
#include <iostream>
using namespace std;

class MyClass
{
    public:
        MyClass();
        void myPrint();
};

MyClass::MyClass() {
}
void MyClass::myPrint() {
    cout <<"Hello"<<endl;
}

int main() {
    MyClass obj;
    MyClass *ptr = &obj;
    ptr->myPrint();
}
```
pointer **ptr** assign (point) to the address of **obj**. 

ptr->myPrint() means **myPrint() function** of pointer ptr.

### Const
- const variables can be initialized in the constructor

### friend
- The friend function of a class is the function that can have access to private and protected the class.
```
#include <iostream>
using namespace std;

class Point {
    public:
        Point(int a, int b): x(a), y(b) {};
        void print() {
            cout << x << ", " << y;
        }
    private:
        int x;
        int y; 
    
    friend void shift(Point &p, int step);
};

void shift(Point &p, int step) {
    p.x += step;
    p.y += step;
}

int main() {
    int x, y;
    cin>>x>>y;
    Point p(x, y);

    int step;
    cin>>step;
    shift(p, step);
    
    p.print();
}
```

