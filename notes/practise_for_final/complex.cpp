#include <iostream>
#include <vector>

using namespace std;

// polymorphism
// static vs dynamic
// // compile
// // // func/opera overload
// // runtime
// // // func/opera override

template<class T>
class Number {
    protected:
        T real, complex; // Real 1 + 0i
    public:
        // default constructor
        Number() {
            real = 1; complex = 0;
        }
        Number(T r) {
            real = r; complex = 0;
        }
        // constructor - default: implicit, explicit does not allow = 
        Number(T v, T com) {
            real = v; 
            complex = com;
        }
        // destructor
        // virtual -> abstract
        virtual ~Number() {}

        virtual void print_number() = 0;

        // int getReal() const {
        //     return real;
        // }

        // int getComplex() const {
        //     return complex;
        // }
};

template<class T>
class Real: public Number<T> {
    public:
        // default constructor is needed for a parent class
        Real() {}
        Real(T value) {
            real = value;
            complex = 0;
        }

        // function override
        void print_number() override {
            cout << "Real number is " << real << endl;
        }

        friend ostream& operator<<(ostream& out, Real& number) {
            out << "Real number is " << number.real << endl;
            return out;
        }

        friend istream& operator>>(istream& in, Real& number) {
            in >> number.real;
            return in;
        }

        friend Real operator+(Real current, Real other) {
            return Real {
                current.real + other.real
            };
        }
};

template<class T>
class Complex: public Real<T> {
    public:
        Complex() {}
        Complex(T real_val, T complex_val) {
            real = real_val;
            complex = complex_val;
        }

        // // Real default constructor is not needed
        // Complex(int real_val, int complex_val): Real(real_val) {
        //     complex = complex_val;
        // }

        void print_number() {
            cout << "Complex number is " << real << "+" << complex << "i" << endl;
        }

        // operator overload
        friend ostream& operator<<(ostream& out, Complex& number) {
            out << "Complex number is " << number.real << "+" << number.complex << "i" << endl;
            return out;
        }

        friend istream& operator>>(istream& in, Complex& number) {
            in >> number.real >> number.complex;
            return in;
        }

        friend Complex operator+(Complex current, Complex other) {
            return Complex {
                current.real + other.real,
                current.complex + other.complex
            };
        }
};

int main() {
    // Number num1;
    // Number num2(1, 0);
    // Number num4 {
    //     1, 0
    // };
    // // implicit
    // Number num3 = {
    //     1, 0
    // };

    // Real num1(2);
    // Complex num2(2, 3);

    Real<int> num1;
    Complex<int> num2;

    cout << "Enter a real number: "; cin >> num1;
    cout << "Enter a complex number: <real><space><complex>: "; cin >> num2;

    cout << num1 << endl;
    cout << num2 << endl;

    // Complex num2(1,3);
    // Complex num3(1,3);
    // Complex num4 = num2 + num3;
    // cout << num4 << endl;

    // Number num_list[2];
    // num_list[0] = {
    //     1, 2
    // };
    // num_list[1] = {1};

    // Number* num_list2[2];

    // num_list2[0] = new Real(2);
    // num_list2[1] = new Complex(2, 1);

    // cout << *num_list2[0];

    // num1.print_number();
    // num2.print_number();
    
    // Number* num_list2[2];

    // num_list2[0] = new Real(2);
    // num_list2[1] = new Complex(2, 1);

    // for (int i = 0; i < 2; ++i) {
    //     num_list2[i]->print_number();
    // }

    // // Freeing the allocated memory
    // for (int i = 0; i < 2; ++i) {
    //     delete num_list2[i];
    // }

    return 0;
}
