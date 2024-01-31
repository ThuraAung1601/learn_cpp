#include "Album.h"
#include<iostream>
using namespace std;

int Album::total_number_of_albums = 0;
double Album::total_revenue = 0;

Album::Album(const string& title, const string& artist, double price, int copies):
    title(title), artist(artist), price(price), copies(copies) {
        Album::total_number_of_albums += Album::copies;
}

void Album::purchase_album() {
    Album::total_number_of_albums--;
    Album::total_revenue += Album::price;
}

int Album::get_total_album() {
    return Album::total_number_of_albums;
}

double Album::get_total_sales() {
    return Album::total_revenue;
}

string Album::get_title() const {
    return Album::title;
}

string Album::get_artist() const {
    return Album::artist;
}

double Album::get_price() const {
    return Album::price;
}