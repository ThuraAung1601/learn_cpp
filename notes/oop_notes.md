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
