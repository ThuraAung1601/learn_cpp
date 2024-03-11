// polymorphism

#include <iostream>
#include <vector>
using namespace std;

#define K 1.2

class Vehicle {
    protected:
        string fuel_type; double energy;
    public:
        Vehicle() {
            fuel_type = "Disel";
            energy = 2.1;
        };
        Vehicle(string fuel, double ener) {
            fuel_type = fuel;
            energy = ener;
        }
        virtual ~Vehicle() {}
        virtual void show_owner() = 0;
        friend ostream& operator<<(ostream& out, Vehicle& v1) {
            out << v1.fuel_type << " " << v1.energy << endl;
            return out;
        }
        virtual double getEnergy() const {
            return energy;
        }
        double operator+(Vehicle& other) {
            return energy + other.energy;
        }
};

class Car : public Vehicle {
    private: 
        int wheels; string owner = "John";
    public:
        Car() {
            wheels = 4;
        }
        Car(string ful, double ene, int w) {
            fuel_type = ful;
            energy = ene;
            wheels = w;
        }
        void setOwner(string name) {
            owner = name;
        }
        void show_owner() override {
            cout << owner << endl;
        }

        friend ostream& operator<<(ostream& out, Car& v1) {
            out << v1.fuel_type << " " << v1.energy << " " << v1.wheels << endl;
            return out;
        }

        friend istream& operator>>(istream& input, Car& c1){
            input >> c1.fuel_type >> c1.energy >> c1.wheels;
            return input;
        }
};

class Bike : public Vehicle {
    private: 
        int wheels; string owner = "John";
    public:
        Bike() {
            wheels = 2;
        }
        Bike(string ful, double ene, int w) {
            fuel_type = ful;
            energy = ene;
            wheels = w;
        }
        void setOwner(string name) {
            owner = name;
        }
        void show_owner() override {
            cout << owner << endl;
        }
        double getEnergy() const override {
            return (energy - (K*energy));
        }
        friend ostream& operator<<(ostream& out, Bike& v1) {
            out << v1.fuel_type << " " << v1.energy << " " << v1.wheels << endl;
            return out;
        }
        friend istream& operator>>(istream& input, Bike& c1){
            input >> c1.fuel_type >> c1.energy >> c1.wheels;
            return input;
        }
};

int main() {
    // Vehicle v1;
    // Vehicle v2("Petrol", 23.1);
    // cout << v1;
    // cout << v2;

    Car c1;
    
    try {
        if(cin >> c1) {
            cout << c1;
        } else {
            throw -1;
        }
    } catch (int x) {
        cout << "Error code " << x << " invalid input !!!" << endl;
    }

    Bike b1;
    // cout << b1;

    Bike b2;
    // cout << b2;

    // double total = c1 + b2;
    
    vector<Vehicle*> vehical_list = {
        &c1, &b1, &b2
    };

    // vehical_list.push_back(&c1);

    // double total = 0;
    // for (auto I: vehical_list) {
    //     total += I->getEnergy();
    // }

    // cout << total << endl;
    return 0;
}
