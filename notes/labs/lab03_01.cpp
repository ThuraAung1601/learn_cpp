#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
using namespace std;

class TemperatureConverter {
    private:
        float temperature; 
    public: 
        // TemperatureConverter(float temp) {
        //     temperature = temp;
        // }
        // TemperatureConverter(float temp) : temperature(temp) { }
        
        void setTemperature(float temp) {
            temperature = temp;
        }

        float convertCelsius2Fahrenheit() {
            return (temperature * 9.0 / 5.0) + 32.0;
        }

        float convertFahrenheit2Celsius() {
            return (temperature - 32.0) * 5.0 / 9.0;
        }
};

int main() {
    TemperatureConverter converter;
    float temp;
    char conversionType;

    while(true) {
        cout << "Enter temperature: "; cin >> temp;
        if (!cin) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a numeric value." << endl;
            continue;
        }

        converter.setTemperature(temp);

        cout << "Convert to (C)elsius or (F)ahrenheit? Enter C or F:";
        cin >> conversionType;

        switch (conversionType) {
            case 'c':
            case 'C': {
                cout << temp << " Fahrenheit is " 
                     << setprecision(3)
                     << converter.convertFahrenheit2Celsius() << " Celsius." << endl;
                break;
            }

            case 'F':
            case 'f': {
                cout << temp << " Celsius is " 
                     << setprecision(3)
                     << converter.convertCelsius2Fahrenheit() << " Fahrenheit." << endl;
                break;
            }

            default: cout << "Invalid input."; continue;
        }

        char choice;
        cout << "Do you want another conversion ? (y/N): "; 
        cin >> choice;
        if (choice == 'N' || choice == 'n') {
            break;
        }
    }
    return 0;
}
