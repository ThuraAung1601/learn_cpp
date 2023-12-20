#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class Book {
    public: 
        string title, author;
        int quantity;  

    void set_title(string newTitle) {
        title = newTitle;
    }

    string get_title() {
        return title;
    }

    void set_author(string newAuthor) {
        author = newAuthor;
    }

    string get_author() {
        return author;
    }

    void set_quantity(int newQuantity) {
        quantity = newQuantity;
    }

    int get_quantity() {
        return quantity;
    }
};

class Inventory {
    public:
        vector<Book> books;
    
    vector<Book> addBook(Book newBook) {
        books.push_back(newBook);
        return books;
    }

    vector<Book> removeBook(string removeTitle) {
        for(int i = 0; i < books.size(); ++i) {
            if (books[i].get_title() == removeTitle) {
                books.erase(books.begin() + i);
            } else {
                continue;
            }
        }
        return books;
    }

    string findBook(string findTitle) {
        for(int i = 0; i < books.size(); ++i) {
            if (books[i].get_title() == findTitle) {
                return "Title: " + books[i].get_title() 
                        + ", Author: " + books[i].get_author()
                        + ", Quantity: " + to_string(books[i].get_quantity());
            }
            else {
                continue;
            }
        }
        return "Not found.";
    }

    void printInventory() {
        if (books.empty()) {
            cout << "There is no book";
        }
        for (int i = 0; i < books.size(); ++i) {
            cout <<  "Book No." + to_string(i+1)
                    + "\nTitle: " + books[i].get_title() 
                    + "\nAuthor: " + books[i].get_author()
                    + "\nQuantity: " + to_string(books[i].get_quantity());
        }
    }
};

int main() {
    char ch;
    string title, author; int quantity;
    Book myBook; 
    Inventory bookList;

    while (true) {
        cout << "Enter command (a: add, s: search, l: list, q: quit): "; 
        cin >> ch;
        cin.ignore();
        if (ch == 'a') {
            cout << "Enter title: "; 
            getline(cin, title);
            // cin >> title;
            cout << "Enter author: "; 
            // cin >> author;
            getline(cin, author);
            cout << "Enter quantity: "; 
            cin >> quantity; cin.ignore();
            // getline(cin, quantity);
            myBook.set_title(title); 
            myBook.set_author(author); 
            myBook.set_quantity(quantity);
            bookList.addBook(myBook);
        }
        else if (ch == 's') {
            cout << "Enter title of the book to search: "; 
            // cin >> title;
            getline(cin, title);
            string result = bookList.findBook(title);
            cout << result << endl; // Display search result
        }
        else if (ch == 'l') {
            bookList.printInventory();
        }
        else if (ch == 'q') {
            break;
        }
        else {
            cout << "Invalid arguments !!!" << endl;
        }
    }

    return 0;
}
