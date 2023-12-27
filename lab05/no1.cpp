#include<iostream>
#include<string>
using namespace std;

struct Date {
    int year, month, day;
};

struct PersonalInfo {
    string first_name, last_name;
    Date birth_date;
};

class HeartRateMonitor {
    private:
        PersonalInfo personal; Date current;
    public:
        HeartRateMonitor(PersonalInfo info) {
            if (info.birth_date.month >= 1 && info.birth_date.month <= 12) {
                int maxDaysInMonth = 31; // Set a default maximum number of days
                if (info.birth_date.month == 4 || info.birth_date.month == 6 || info.birth_date.month == 9 || info.birth_date.month == 11) {
                    maxDaysInMonth = 30; // April, June, September, November have 30 days
                } else if (info.birth_date.month == 2) {
                    // February can have 28 or 29 days depending on the year (not handling leap years here)
                    maxDaysInMonth = 28;
                }

                if (info.birth_date.day >= 1 && info.birth_date.day <= maxDaysInMonth) {
                    personal = info;
                } else {
                    cout << "Invalid day for the specified month!" << endl;
                }
            } else {
                cout << "Invalid month!" << endl;
            }
            // fixed value
            current.year = 2023;
            current.month = 12;
            current.day = 28;
        }

        int calculateAge() const {
            int age = current.year - personal.birth_date.year;
            // Check if the birthday has passed this year
            if (current.month < personal.birth_date.month || (current.month == personal.birth_date.month && current.day < personal.birth_date.day)) {
                age--;
            }
            return age;
        }

        int calculateMaxHeartRate() {
            return 220 - calculateAge();
        }

        string displayInformation() {
            int upper_limit_target_heart_rate = 0.5 * calculateMaxHeartRate();
            int lower_limit_target_heart_rate = 0.85 * calculateMaxHeartRate();

            return "Hello, " + to_string(calculateAge()) + " years old " + personal.first_name + " " + personal.last_name + "."
                    + "\n" + "Your maximum heart rate should be " + to_string(calculateMaxHeartRate()) + " beats per minute."
                    + "\n" + "Your target heart rate range is " + to_string(upper_limit_target_heart_rate) + "-" + to_string(lower_limit_target_heart_rate) + " beats per minute.";
         }
};

int main() {
    PersonalInfo info;
    cout << "Enter first name: "; cin >> info.first_name;
    cout << "Enter last name: "; cin >> info.last_name; 
    cout << "Enter your birth year (YYYY): "; cin >> info.birth_date.year;
    cout << "Enter your birth month (MM): "; cin >> info.birth_date.month;
    cout << "Enter your birth day (DD): "; cin >> info.birth_date.day;

    HeartRateMonitor myHeartRater(info);
    cout << myHeartRater.displayInformation() << endl;
    return 0;
}
