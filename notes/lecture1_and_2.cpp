#include <iostream>
#include <string>
#include<iomanip>
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

  double x = 1.2;
  int y = x;
  cout << x << "'s integer is " << y << endl;
  //   double z = y; // error  
  
  double xx = 2.24;
  int yy = (int) xx;
  float zz = (float) (xx/yy);
  cout << xx << "'s integer is " << yy << " and divided value is " << zz << endl;
  return 0;
}
