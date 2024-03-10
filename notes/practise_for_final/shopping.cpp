#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

#define VAT 0.1

template <class T>
string setPrecision(T num, int precision) {
    string result;
    string value = to_string(num);
    size_t position = value.find('.');
    for (int i=1; i < (value.size()-(position+precision)); i++) {
        int temp = value[position+precision+i] - '0';
        if (temp >= 5) {
            value[(position+precision+i)-1] += 1;
        }
    }
    result = value.substr(0, position+precision+1);
    return result;
}

class Item {
    protected:
        string name; double price;
    public:
        Item() {}
        virtual ~Item() {}

        void setName(string n) {
            name = n;
        }
        string getName() {
            return name;
        }
        void setPrice(double p) {
            price = p;
        }
        virtual double getPrice() {
            return price;
        }

        // Define the output operator overload for Item class
        friend ostream& operator<<(ostream& out, Item& item) {
            out << "Name: " << item.getName() << endl;
            out << "Price: " << item.getPrice() << endl;
            return out;
        }
};

class Book : public Item {
    private:
        string author;
    public:
        Book(string title, string a, double p) {
            author = a;
            name = title;
            price = p;
        }
        ~Book() {}
        void setAuthor(string a) {
            author = a;
        }
        string getAuthor() {
            return author;
        }

        friend ostream& operator<<(ostream& out, Book& b1) {
            out << "Name: " << b1.getName() << endl
                << "Author: " << b1.getAuthor() << endl
                << "Price:" << b1.getPrice() << endl;
            return out;
        }
};

class Food: public Item {
    protected:
        double calorie;
    public:
        Food() {}
        virtual ~Food() {};
};

class Snack: public Food {
    private:
        double promotion = 0.25;
    public:
        Snack(string n, double cal, double p) {
            name = n; calorie = cal; price = p;
        }
        ~Snack() {}

        void setPromotion(double promo) {
            promotion = promo;
        }

        double getCalorie() {
            return calorie;
        }

        double getPrice() override {
            return price - (price*promotion);
        }

        friend ostream& operator<<(ostream& out, Snack& s1) {
            out << "Name: " << s1.getName() << endl
                << "Calorie: " << s1.getCalorie() << endl
                << "Price:" << s1.getPrice() << endl;
            return out;
        }
};

int main() {

    // ---------------- Each Item -----------------------------
    Book b1 (
        "Hello", "John", 12.34
    );
    // cout << b1.getName() << endl <<
    // b1.getPrice() << endl << 
    // b1.getAuthor() << endl;
    // cout << b1.getAuthor() << endl;
    Snack item1 = {
        "Pizza", 120, 100
    };
    // cout << item1.getPrice() << endl;

    // ---------------- Using Vector -----------------------------
    // vector<Item> shopping_list = {
    //     b1, item1
    // };
    // cout << shopping_list[1].getName() << endl;
    // cout << shopping_list[1].getPrice() << endl;
    // cout << item1;

    // ---------------- Using Pointer ----------------------------
    vector<Item*> shopping_list2;
    shopping_list2.push_back(&b1); 
    shopping_list2.push_back(&item1);
    // cout << shopping_list2[1]->getName() << endl;
    // cout << shopping_list2[1]->getPrice() << endl;

    // ---------- Find the total price with VAT ------------
    double totalPrice = 0;
    for (auto I: shopping_list2) {
        totalPrice += I->getPrice();
    }
    totalPrice += totalPrice*VAT;
    cout << "Total Price with VAT is " << setPrecision(totalPrice, 2) << endl; 

    // ---------- File Operation --------------

    // reading a file
    ifstream myFile("test.txt"); 
    if (myFile.is_open()) {
        string line;
        while(getline(myFile, line)) {
            cout << line << endl;
        }
        myFile.close();
    } else {
        cerr << "Error: File not open!!!" << endl;
    }

    // writing a file
    ofstream outFile("shoppingList.txt");
    if (outFile.is_open()) {
        for (Item* i: shopping_list2) {
            outFile << *i;
        }
        outFile << "Total Price with VAT is " << setPrecision(totalPrice, 2) << endl;
        outFile.close(); 
    }
    return 0;
}
