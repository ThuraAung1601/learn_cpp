#ifndef ALBUM_H
#define ALBUM_H
#include<string>
using namespace std;
class Album {
    private: 
        const string title; const string artist; double price; int copies;
        static int total_number_of_albums; static double total_revenue;
    public:
        Album(const string&, const string&, double , int);
        void purchase_album();
        static int get_total_album();
        static double get_total_sales();

        string get_title() const;
        string get_artist() const;
        double get_price() const;
        int get_copies() const;
};
#endif