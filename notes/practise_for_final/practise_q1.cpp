/*
    Implement a program that models different shapes 
    (e.g., circle, rectangle) using polymorphism 
    and an abstract base class Shape. 
    Each shape should have a method to calculate its area. 
    Test your program by creating instances of different shapes and calculating their areas
*/

#include <iostream>
using namespace std;

#define PI 3.142

template <class T>
class Shape {
    public:
        Shape() {}
        ~Shape() {}
        virtual T area() const = 0;
        virtual void info() = 0;
};

template <class T>
class Circle: public Shape<T> {
    private:
        T radius;
    public:
        Circle() {radius = 0;};
        Circle(T r) {
            radius = r;
        }
        ~Circle() {}
        T area() const override {
            return radius * radius * PI;
        }

        void info() override {
            cout << "radius: " << radius << endl 
                 << "area: " << area() << endl;
        }

        friend istream& operator>>(istream& in, Circle& circle) {
            in >> circle.radius;
            return in;
        }
};

template <class T>
class Rectangle: public Shape<T> {
    private:
        T width, height;
    public:
        Rectangle() {width = 0; height = 0;};
        Rectangle(T w, T h) {
            width = w; height = h;
        }
        ~Rectangle() {}
        T area() const override {
            return width * height;
        }

        void info() override {
            cout << "width: " << width << endl
                 << "height: " << height << endl
                 << "area: " << area() << endl;
        }

        friend istream& operator>>(istream& in, Rectangle& rec) {
            in >> rec.width >> rec.height;
            return in;
        }
};

int main() {
    // error: Circle c1(1.2); 
    Circle<double> c1(1.2);
    Rectangle<int> r1(3, 5);
    c1.info(); r1.info();
    
    Circle<int> c2;
    cout << "Enter circle radius: ";
    
    try {
        if(cin >> c2) {
            c2.info();
        } else {
            throw -1;
        }
    } catch (int x) {
        cout << "Error !!!" << endl;
        return 1;
    }

    Rectangle<double> r2;
    cout << "Enter width and height of rectangle: ";
    
    try {
        if(cin >> r2) {
            r2.info();
        } else {
            throw -1;
        }
    } catch (int x) {
        cout << "Error !!!";
    }

    return 0;
}