#include <iostream>
#include <vector>
using namespace std;

template <class T>
class Complex {
    private:
        T real, complex;
    public:
        Complex() {}
        ~Complex() {}
        // Complex(T r, T c) {
        //     real = r; complex = c;
        // }
        Complex(T r, T c): real(r), complex(c) {}
        
        // friend function: not a member but within the class and can access private instances
        // friend Complex operator+(Complex num, Complex other) {
        //     return Complex {
        //         num.real + other.real,
        //         num.complex + other.complex
        //     };
        // }

        // member function: can access private parts directly and can use this->
        Complex operator+(Complex other) {
            return Complex {
                this->real + other.real,
                this->complex + other.complex
            };
        }

        bool operator!=(Complex other) {
            if (this->real != other.real || this->complex != other.complex) {
                return true;
            }
            return false;
        }

        bool operator>(Complex other) {
            if (this->real > other.real || this->complex > other.complex) {
                return true;
            }
            return false;
        }

        bool operator<(Complex other) {
            if (this->real < other.real || this->complex < other.complex) {
                return true;
            }
            return false;
        }

        bool operator>=(Complex other) {
            if (this->real >= other.real || this->complex >= other.complex) {
                return true;
            }
            return false;
        }

        bool operator<=(Complex other) {
            if (this->real <= other.real || this->complex <= other.complex) {
                return true;
            }
            return false;
        }

        bool operator==(Complex other) {
            if (this->real == other.real && this->complex == other.complex) {
                return true;
            }
            return false;
        }

        T getReal() const {
            return real;
        }

        T getComplex() const {
            return complex;
        }

        Complex& operator=(Complex& other) {
            if (this != &other) {
                this->real = other.real;
                this->complex = other.complex;
            } 
            return *this;
        }

        friend ostream& operator<<(ostream& out, Complex number) {
            out << number.real << ((number.complex >= 0) ? "+" : "-") << number.complex << "i";
            return out;
        }

        friend istream& operator>>(istream& in, Complex number) {
            in >> number.real >> number.complex;
            return in;
        }
};

int main() {
    Complex<int> num1(2, 1); Complex<int> num2(1, 2);
    Complex<int> num3 = num1 + num2;
    Complex<int> num4 = num3;
    cout << num1 << endl;
    cout << num2 << endl;
    cout << num4 << endl;
    cout << (num4 <= num2) << endl;
    cout << (num4 != num2) << endl;

    // Dynamic memory allocations
    vector<Complex<int>*> num_ls1;
    Complex<int>* num_ls2[3];
    Complex<int>* num_ls3 = new Complex<int>[3];

    num_ls1.push_back(&num1);
    num_ls2[0] = &num1;
    num_ls3[0] = num1;

    cout << *num_ls1[0] << endl;
    cout << *num_ls2[0] << endl;
    cout << num_ls3[0] << endl;

    cout << num_ls1[0]->getReal() << endl;
    cout << num_ls2[0]->getReal() << endl;
    cout << num_ls3[0].getReal() << endl;

    delete[] num_ls3;
    return 0;
}