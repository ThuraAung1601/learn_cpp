#include <iostream>
#include <vector>

class Polynomial {
private:
    std::vector<int> coefficients;

public:
    // Constructor to initialize the polynomial with coefficients
    Polynomial(const std::vector<int>& coeffs) : coefficients(coeffs) {}

    // Default constructor
    Polynomial() {}

    // Function to set the coefficient for a specific term of the polynomial
    void set_poly(int coeff, int power) {
        // Ensure the coefficients vector has enough elements to represent the power
        if (power >= coefficients.size()) {
            coefficients.resize(power + 1, 0);
        }
        coefficients[power] = coeff;
    }

    // Function to evaluate the polynomial for a given value of x
    int evaluate(int x) const {
        int result = 0;
        int power = 1;
        for (int coeff : coefficients) {
            result += coeff * power;
            power *= x;
        }
        return result;
    }

    // Function to get the degree of the polynomial
    int degree() const {
        return coefficients.size() - 1;
    }

    // Overloading the + operator to add two polynomials
    Polynomial operator+(const Polynomial& other) const {
        int maxSize = std::max(coefficients.size(), other.coefficients.size());
        std::vector<int> resultCoeffs(maxSize);
        for (int i = 0; i < maxSize; ++i) {
            int coeff1 = (i < coefficients.size()) ? coefficients[i] : 0;
            int coeff2 = (i < other.coefficients.size()) ? other.coefficients[i] : 0;
            resultCoeffs[i] = coeff1 + coeff2;
        }
        return Polynomial(resultCoeffs);
    }

    // Overloading the - operator to subtract two polynomials
    Polynomial operator-(const Polynomial& other) const {
        int maxSize = std::max(coefficients.size(), other.coefficients.size());
        std::vector<int> resultCoeffs(maxSize);
        for (int i = 0; i < maxSize; ++i) {
            int coeff1 = (i < coefficients.size()) ? coefficients[i] : 0;
            int coeff2 = (i < other.coefficients.size()) ? other.coefficients[i] : 0;
            resultCoeffs[i] = coeff1 - coeff2;
        }
        return Polynomial(resultCoeffs);
    }

    // Overloading the * operator to multiply two polynomials
    Polynomial operator*(const Polynomial& other) const {
        std::vector<int> resultCoeffs(coefficients.size() + other.coefficients.size() - 1, 0);
        for (int i = 0; i < coefficients.size(); ++i) {
            for (int j = 0; j < other.coefficients.size(); ++j) {
                resultCoeffs[i + j] += coefficients[i] * other.coefficients[j];
            }
        }
        return Polynomial(resultCoeffs);
    }

    // Overloading the << operator to print the polynomial
    friend std::ostream& operator<<(std::ostream& out, const Polynomial& poly) {
        bool firstTerm = true;
        for (int i = poly.coefficients.size() - 1; i >= 0; --i) {
            if (poly.coefficients[i] != 0) {
                if (poly.coefficients[i] > 0) {
                    out << "+";
                }
                out << poly.coefficients[i];
                out << "x^" << i;
                firstTerm = false;
            }
        }
        if (firstTerm) {
            out << "0"; // Print 0 if polynomial is empty
        }
        return out;
    }
};

int main() {
    Polynomial poly1, poly2;

    poly1.set_poly(2, 3); // 2x^3
    poly1.set_poly(4, 1);  // 4x^1
    std::cout << "Poly 1: " << poly1 << std::endl;

    poly2.set_poly(3, 2);
    poly2.set_poly(5, 0);
    std::cout << "Poly 2: " << poly2 << std::endl;

    Polynomial p3 = poly1 + poly2;
    Polynomial p4 = poly1 - poly2;
    Polynomial p5 = poly1 * poly2;

    std::cout << "Poly 3: " << p3 << std::endl;
    std::cout << "Poly 4: " << p4 << std::endl;
    std::cout << "Poly 5: " << p5 << std::endl;
    return 0;
}