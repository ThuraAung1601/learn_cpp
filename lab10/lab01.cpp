#include <iostream>
#include <sstream>

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

class Fraction {
private:
    int numerator;
    int denominator;

public:
    Fraction(int num = 0, int denom = 1) : numerator(num), denominator(denom) {}

    // Overloading the '+' operator to add two Fraction objects
    Fraction operator+(const Fraction& other) const {
        int num = numerator * other.denominator + other.numerator * denominator;
        int denom = denominator * other.denominator;
        int commonDivisor = gcd(num, denom);
        num = num / commonDivisor;
        denom = denom / commonDivisor;
        return Fraction(num, denom);
    }

    // Overloading the '-' operator to subtract two Fraction objects
    Fraction operator-(const Fraction& other) const {
        int num = numerator * other.denominator - other.numerator * denominator;
        int denom = denominator * other.denominator;
        int commonDivisor = gcd(num, denom);
        num = num / commonDivisor;
        denom = denom / commonDivisor;
        return Fraction(num, denom);
    }

    // Overloading the '*' operator to multiply two Fraction objects
    Fraction operator*(const Fraction& other) const {
        int num = numerator * other.numerator;
        int denom = denominator * other.denominator;
        int commonDivisor = gcd(num, denom);
        num = num / commonDivisor;
        denom = denom / commonDivisor;
        return Fraction(num, denom);
    }

    // Overloading the '/' operator to divide two Fraction objects
    Fraction operator/(const Fraction& other) const {
        if (other.numerator == 0) {
            std::cerr << "Division by zero error!" << std::endl;
            return Fraction(); // Return a default-constructed Fraction object
        }
        int num = numerator * other.denominator;
        int denom = denominator * other.numerator;
        int commonDivisor = gcd(num, denom);
        num = num / commonDivisor;
        denom = denom / commonDivisor;
        return Fraction(num, denom);
    }

    // Overloading the '==' operator to compare two Fraction objects for equality
    bool operator==(const Fraction& other) const {
        int commonDivisor1 = gcd(numerator, denominator);
        int num1 = numerator / commonDivisor1;
        int denom1 = denominator / commonDivisor1;

        int commonDivisor2 = gcd(other.numerator, other.denominator);
        int num2 = other.numerator / commonDivisor2;
        int denom2 = other.denominator / commonDivisor2;

        return (num1 == num2 && denom1 == denom2);
    }

    // Overloading the '!=' operator to compare two Fraction objects for inequality
    bool operator!=(const Fraction& other) const {
        return !(*this == other); // Utilizing the '==' operator overload
    }

    // Friend function for output formatting (optional)
    // that overloads the << operator to allow printing of Fraction objects to output streams
    friend std::ostream& operator<<(std::ostream& out, const Fraction& result) {
        out << result.numerator << "/" << result.denominator;
        return out;
    }

    // Overloading the '>>' operator to allow input of Fraction objects
    friend std::istream& operator>>(std::istream& in, Fraction& frac) {
        std::string input;
        in >> input;

        // Parse input string
        std::stringstream ss(input);
        std::string token;
        std::getline(ss, token, '/');
        frac.numerator = std::stoi(token);
        std::getline(ss, token, '/');
        frac.denominator = std::stoi(token);
        if (frac.denominator == 0) {
            std::cerr << "Invalid input: Denominator cannot be ZERO.";
            in.setstate(std::ios_base::failbit); //modify with stdexcept
        }
        return in;
    }
};

int main() {
    Fraction num1;
    Fraction num2;

    std::cout << "Enter a fraction 1: ";
    std::cin >> num1;
    std::cout << "Enter a fraction 2: ";
    std::cin >> num2;

    Fraction sum = num1 + num2;
    Fraction diff = num1 - num2;
    Fraction muli = num1 * num2;
    Fraction divi = num1 / num2;

    std::cout << "Our sum is " << sum << std::endl;
    std::cout << "Our difference is " << diff << std::endl;
    std::cout << "Our muliple is " << muli << std::endl;
    std::cout << "Our division is " << divi << std::endl;

    if (num1 == num2)
        std::cout << "num1 and num2 are equal." << std::endl;
    else
        std::cout << "num1 and num2 are not equal." << std::endl;

    return 0;
}
