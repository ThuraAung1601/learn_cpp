// Write a program that accomplishes each of the following:
// a) Create a user-defined class Point that contains the private integer data members xCoordinate and yCoordinate and
// declares stream insertion and stream extraction over-loaded operator functions as friends of the class.

// b) Definethestreaminsertionandstreamextractionoperatorfunctions.Thestreamex-
// traction operator function should determine whether the data entered is valid, and, if not, it should set the failbit to indicate

// improper input. The stream insertion operator should not be able to display the point after an input error occurred.
// c) Write a main function that tests input and output of user-defined class Point, using the overloaded stream extraction and
// stream insertion operators.

#include <iostream>
using namespace std;

class Point {
    private:
        int xCoordinate, yCoordinate;

    public:
        // Constructor
        Point(int x = 0, int y = 0) : xCoordinate(x), yCoordinate(y) {}

        // Getter functions
        int getXCoordinate() const { return xCoordinate; }
        int getYCoordinate() const { return yCoordinate; }

        // Stream insertion operator overload (friend function)
        friend std::ostream& operator<<(std::ostream& out, const Point& point) {
            out << "(" << point.xCoordinate << ", " << point.yCoordinate << ")";
            return out;
        }

        // Stream extraction operator overload (friend function)
        // friend std::istream& operator>>(std::istream& in, Point& point) {
        //     in >> point.xCoordinate;
        //     in >> point.yCoordinate;
        //     return in;
        // }

        // Stream extraction operator overload (friend function)
        friend std::istream& operator>>(std::istream& in, Point& point) {
            int x, y;
            in >> x;
            if (!in.good()) {
                in.clear(); // Clear error flags
                in.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer
                return in;
            }
            in >> y;
            if (!in.good()) {
                in.clear(); // Clear error flags
                in.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer
                return in;
            }
            point.xCoordinate = x;
            point.yCoordinate = y;
            return in;
    }
};

int main() {
    Point point;
    // Input from the user
    std::cout << "Enter the coordinates of the point:" << std::endl;
    std::cin >> point;
    // Output the point
    std::cout << "The point is: " << point << std::endl;
    return 0;
}
