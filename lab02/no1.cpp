// Create a C++ program that uses object-oriented programming to convert temperatures between Celsius and
// Fahrenheit. The program should con=nuously prompt the user to enter a temperature and the desired conversion
// (Celsius to Fahrenheit or Fahrenheit to Celsius) un=l the user decides to exit.
// a. Implement a class TemperatureConverter with the following func=onali=es:
// i. A method to convert from Celsius to Fahrenheit.
// ii. A method to convert from Fahrenheit to Celsius.
// b. The main func=on should use a while loop to:
// i. Prompt the user to enter a temperature and the desired conversion type.
// ii. Use an instance of TemperatureConverter to perform the conversion.
// iii. Display the converted temperature.
// iv. Ask the user if they want to perform another conversion. The program should con=nue un=l the user
// chooses to exit.
// c. Include input valida=on to handle non-numeric inputs and invalid temperature types.

#include<iostream>
#include<string>
using namespace std;

class TemperatureConverter {
    private: 
        float temperature;
    public:
        TemperatureConverter(float temp): temperature(temp) { }

        float C2F() {
            return (temperature * 9 / 5) + 32;
        }

        float F2C() {
            return (temperature - 32) * 5 / 9;
        }
};

bool isNumber(const string &temp) {
    for (int i = 0; i < temp.length(); i++) {
        if (!(isdigit(temp[i]) || temp[i] == '.')) {
            return false;
        }
    }
    return true;
}

int main() {
    string temp; char c;
    
    while (true) {
        cout << "Enter Temperature value: "; 
        cin >> temp;
        if (isNumber(temp)) {
            float temperature = stof(temp);
            TemperatureConverter TC(temperature);

            cout << "Press \'1\' for C2F and \'2\' for F2C\': "; cin >> c;
            if (c == '1') {
                cout << "The Fahrenheit value of " << temp << " is " << TC.C2F() << endl;
            }
            else if (c == '2') {
                cout << "The Celsius value of " << temp << " is " << TC.F2C() << endl;
            }
            else {
                cout << "Only \'1\' and \'2\' accepted.";
            }

            char quit;
            cout << "Do you want to quit ? (Y/n): "; cin >> quit;
            if (quit == 'Y' || quit == 'y') {
                break;
            }
            else {
                continue;
            }
        }
        else {
            cout << "Retype again !!!\nOnly numerical values accepted."<<endl;
        }
    }

    return 0;
}