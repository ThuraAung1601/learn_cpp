// Lecture 5
// Classes, objects, algorithm development and control statements
// 27th December 2023
// Thura Aung

#include<iostream>
#include<string>
#include<sstream>
#include<iomanip>

using namespace std;

// implicit constructor by default
class Account1 {
    private:
        string name;
    public:
        // created automatically by compiler 
        // - whether inside the code or not
        // Account1() {

        // }

        void setName(string accountName) {
            name = accountName;
        }
        // should put const to show compiler error in case the value in name is changed.
        string getName() const {
            return name;
        }
};

// w/ explicit constructor
class Account2 {
    private:
        string name;
    public:
        // constructors = function same name with the class
        // explicitly defined constructor
        explicit Account2(string accountName) : name(accountName) {

        }
    void setName(string accountName) {
        name = accountName;
    }
    // should put const to show compiler error in case the value in name is changed.
    string getName() const {
        return name;
    }
};

// w/ data validation
class Account3 {
    private:
        string name; int balance;
    public:
        // constructors = function same name with the class
        // explicitly defined constructor
        explicit Account3(string accountName, int initialBalance) : name(accountName) {
            // setting default to zero if less than 0
            if (initialBalance > 0) {
                balance = initialBalance;
            }
        }
        void setName(string accountName) {
            name = accountName;
        }
        // should put const to show compiler error in case the value in name is changed.
        string getName() const {
            return name;
        }

        void setBalance(int initialBalance) {
            balance = initialBalance;
        }
        // should NOT put const to show compiler error in case the value in name is changed.
        int getBalance() {
            return balance;
        }
};

// without library
bool isNumber(const string& str) {
    for (int c = 0; c < str.size(); c++) {
        if (!(isdigit(str[c]) || str[c] == '.')) {
            return false;
        }
    }
    return true;
}

bool isInteger(const string& str) {
    istringstream iss(str);
    int num;
    // will extract integer part
    iss >> num;
    // eof: end of file(object)
    return iss.eof() && !iss.fail();
}

int main() {
    Account1 myAccount;

    myAccount.setName("John");
    cout << myAccount.getName() << endl;

    // cout << "Enter your name: ";
    // string theName;
    // getline(cin, theName);
    // cout << "The name is " << theName << endl;

    // myAccount.setName(theName);
    // cout << "The name to myAccount object is " << myAccount.getName() << endl;

    // ----------------- w/ explicit constructor 

    Account2 myAccount2("Alex");
    // reset the name in myAccount2
    // myAccount2.setName("Athena");
    cout << myAccount2.getName() << endl;

    // ----------------- w/ data validation 

    Account3 myAccount3("Alex", 100);
    cout << myAccount3.getName() << endl;
    cout << myAccount3.getBalance() << endl;

    Account3 myAccount4("Alex", -1);
    cout << myAccount4.getName() << endl;
    cout << myAccount4.getBalance() << endl;

    // ----------------- data validation - check int float 

    cout << isInteger("100") << endl;
    // integer
    cout << (isInteger("100") ? "Integer": "Not integer") << endl;
    // not integer
    cout << (isInteger("100.5") ? "Integer": "Not integer") << endl;

    cout << (isNumber("100.5") ? "Number": "Not number") << endl;

    float floatValue;
    cout << "Enter a floating number: ";
    while (!(cin >> floatValue)) {
        cout << "Retype float value: ";
        // reset the error state of the input stream
        cin.clear();
        // discard characters from the input buffer
        // - always use before getline if there is any use of cin prior
        // cin.ignore();

        // pass numeric_limit to avoid unnecessary loops
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << "Entered float value is " << floatValue << endl;

    // ----------------- istringstream class

    // String Parsing
    string data = "123 3.142 Hello";
    istringstream iss(data);
    int intValue; float floatvalue; string stringValue;
    // extract int float string values
    iss >> intValue;
    iss >> floatvalue;
    iss >> stringValue;
    
    cout << "Integer: " << intValue << endl 
         << "Float: "  << floatvalue << endl 
         << "String: "  << stringValue << endl;

    // ----------------- Sentinel loop
    // loop continues to execute 
    // - until it encounters a specific value within the input

    // example: print even numbers less than 10
    int num = 0;
    int sentinalValue = 10;
    while (true) {
        if (num % 2 == 0) {
            cout << num << "|";
            num++;
        } else if (num >= sentinalValue) {
            break;
        } else {
            num++;
        }
    }
    cout << endl;

    // ----------------- Floating number formatting for data manipulation
    double number = 12345.6789;
    cout << fixed << number << endl;
    cout << setprecision(2) << number << endl;
    cout << setw(10) << number << endl;
    
    cout << scientific << number;
    cout << setprecision(2) << number << endl;
    
    return 0;
}
