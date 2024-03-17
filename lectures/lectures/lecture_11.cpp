#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

enum BookType {
    Fiction, 
    NonFiction,
    Reference
};

struct Date {
    int day;
    int month;
    int year;

    Date& operator=(Date& other) {
        this->day = other.day;
        this->month = other.month;
        this->year = other.year;

        return *this;
    }
};

struct Book {
    string title;
    string author;
    int publication_year;

    Book& operator=(Book& other) {
        this->title = other.title;
        this->author = other.author;
        this->publication_year = other.publication_year;

        return *this;
    }
};

int _cal_allowed_period(BookType type) {
    int days = 0;
    switch(type) {
        case BookType::Fiction: days = 15; break;
        case BookType::NonFiction: days = 20; break;
        case BookType::Reference: days = 30; break;
        default: break;
    }
    return days;
}

class CheckOut {
    private:
        string member_name; 
        Date date; 
        Book book;
        BookType book_type;
    public:
        CheckOut() {}
        ~CheckOut() {}
        CheckOut(string member_name, Date date, Book book, BookType book_type) {
            this->member_name = member_name;
            this->date = date;
            this->book = book;
            this->book_type = book_type;
        }

        friend ostream& operator<<(ostream& out, CheckOut book) {
            out << "Person Borrowed: " << setw(10) << book.member_name << endl
                << "Date: " << setw(16) << book.date.day << "/" << book.date.month << "/" << book.date.year << endl
                << "Allowed for: " << setw(10) << _cal_allowed_period(book.book_type) << endl
                << "Book: " << setw(10) << book.book.title << " written by " << book.book.author << endl;
            return out;
        }
};

int main() {
    CheckOut no1 = {
        "John", 
        {
            1, 2, 2024
        },
        {
            "Adventure at Academia",
            "Thura Aung",
            2032
        },
        NonFiction
    };

    CheckOut no2 = {
        "Taylor", 
        {
            1, 2, 2024
        },
        {
            "Computational linguistics for Myanmar language",
            "Thura Aung",
            2034
        },
        Reference
    };

    CheckOut no3 = {
        "Taylor", 
        {
            1, 2, 2024
        },
        {
            "Professor and the cleaning lady",
            "Thura Aung",
            2035
        },
        Fiction
    };

    cout << no3;

    vector<CheckOut> checkout_list = {
        no1, no2, no3
    };

    // ios::app is to append the existing text file
    ofstream myFile("check_out_list.txt", ios::app);
    if (myFile.is_open()) {  // if(!myFile.fail())
        for(CheckOut i: checkout_list) {
            myFile << i << endl;
        }
    } else {
        cerr << "Error:: File cannot opened";
        exit(1);
    };

    if (myFile.is_open()) {  // if(!myFile.fail())
        myFile << no1 << endl;
    } else {
        cerr << "Error:: File cannot opened";
        exit(1);
    };

    myFile.close();

    // read from the file
    ifstream myFile1("check_out_list.txt");
    string line;
    while (getline(myFile1, line)) {
        cout << line << endl;
    }
    myFile1.close();
    return 0;
}