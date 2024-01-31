#include<iostream>
#include<vector>
#include "Album.h"
using namespace std;

void display(vector<Album>& album_list) {
    cout << "Available albums are ..." << endl;
    for (size_t i = 0; i < album_list.size(); i++) {
        cout << i+1 << ". " << album_list[i].get_title() << " by ";
        cout << album_list[i].get_artist() << " - $";
        cout << album_list[i].get_price() << " (";
        cout << album_list[i].get_total_album() << " copies available)" << endl;
    }
}

void purchase(vector<Album>& album_list) {
    display(album_list);
    int i;
    cout << "Enter Album ID to purchase: ";
    cin >> i;

    if (i >= 1 && i <= static_cast<int>(album_list.size())) {
        album_list[i-1].purchase_album();
        cout << "Congratulations. Successfully purchased." << endl;
    } else {
        cout << "Invalid Album ID. Please enter a valid ID." << endl;
    }
}

// void display_stats(vector<Album>& album_list) {
//     cout << "Total albums in the inventory: " << Album::get_total_album() << endl;
//     // double total_sales{0};
//     // for (size_t i = 0; i < album_list.size(); i++) {
//     //     total_sales += album_list[i].get_total_sales();
//     //     // cout << i << total_sales << endl;
//     // }
//     cout << "Total sales made: " << Album::get_total_sales() << endl;
// }

void display_stats(vector<Album>& album_list) {
    cout << "Total albums in the inventory: " << Album::get_total_album() << endl;
    cout << "Total sales made: " << Album::get_total_sales() << endl;
}

int main() {
    vector<Album> albums;
    albums.emplace_back("Abbey Road", "The Beatles", 19.99, 5);
    albums.emplace_back("The Dark Side of the Moon", "Pink Floyd", 21.99, 3);
    albums.emplace_back("Hotel California", "Eagles", 15.99, 4);
    albums.emplace_back("Back in Black", "AC/DC", 20.99, 2);

    bool conditional = true;
    do {
        cout << "Online music store menu: " << endl;
        cout << "1. List all albums." << endl;
        cout << "2. Purchase an album." << endl;
        cout << "3. Display sales statistics." << endl;
        cout << "4. Exit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: 
                display(albums); break;
            case 2: 
                purchase(albums); break;
            case 3: 
                display_stats(albums); break;
            case 4: 
                conditional = false; break;
            default: 
                cout << "Invalid choice. Please enter a valid option." << endl; break;
        }
    } while(conditional);

    return 0;
}