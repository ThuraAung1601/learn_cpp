#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

vector<string> rounds = {"12:00", "15:00", "18:00", "21:00"};

struct Seat {
    string date;
    vector<vector<bool>> seats;
};

struct Movie {
    string title;
    vector<string> date;
    vector<Seat> availableSeats;
};

struct Reservation {
    string customerName;
    string movieTitle;
    string date;
    int round;
    int seatNumber;
};

void displaySchedule(const vector<Movie>& movies) {
    for (const Movie& m : movies) {
        cout << m.title << endl;

        for (size_t i = 0; i < m.availableSeats.size(); i++) {
            cout << "(" << m.availableSeats[i].date << ")-";

            for (int row = 0; row < 4; row++) {
                int seat_count = 0;
                for (int col = 0; col < 10; col++) {
                    if (m.availableSeats[i].seats[row][col]) {
                        seat_count++;
                    }
                }
                cout << setw(7) << rounds[row] << ": " << seat_count << " available";
            }
            cout << endl;
        }
    }
}

void makeReservation(vector<Movie>& movies) {

    int movie_index = 0;
    int date_index=0;
    int round_index=0;
    int num_seat=0;
    select_movie:
    cout<<"Please select a movie :"<<endl;
    for(int i=0; i < movies.size(); i++){
        cout<<i+1<<") "<< movies[i].title<<endl;
    }

    cout<<"Enter movie number : ";
    cin>> movie_index;
    if(movie_index<1 || movie_index > movies.size()){
        cout<<"Invalid movie number "<<endl;
        goto select_movie;
    }

    movie_index -=1;
    select_date:
    cout<<"Please select a date:"<<endl;
    for(int i=0; i < movies[movie_index].date.size(); i++){
        cout<<i+1<<") "<<movies[movie_index].date[i]<<endl;
    }
    cout<<"Enter date : ";
    cin>> date_index;
    

    if(date_index<1 || date_index > movies[movie_index].date.size()){
        cout<<"Invalid date choice "<<endl;
        goto select_date;
    }
    date_index -=1;


    select_round:
    cout<<"Please select a round:"<<endl;
    vector<int> available_seats={};
    


    for(int row=0; row < movies[movie_index].availableSeats[date_index].seats.size(); row++){
        
        int seat_count=0;
        cout<< "Round "<<row+1<<")- ";
        for(int col=0; col < 10; col++){
            if(movies[movie_index].availableSeats[date_index].seats[row][col]){
                seat_count ++;
            }
        }
        available_seats.push_back(seat_count);
        cout<< seat_count <<" seat left"<<endl;
        
    }


    cout<<"Enter round : ";
    cin>> round_index;
    

    if(round_index<1 || round_index > 4){
        cout<<"Invalid round choice "<<endl;
        goto select_round;
    }
    round_index -=1;

    select_seat:
    cout<<"Enter the number of seats : ";
    cin>>num_seat;

    if(num_seat < 0 || num_seat > available_seats[round_index]){
        cout<<"Invalid seat number !"<<endl;
        goto select_seat;
    }

    for(int i=0; i< num_seat;i++){

        for(int col=0; col < 10; col++){
                bool status = movies[movie_index].availableSeats[date_index].seats[round_index][col];
                if(status){
                     movies[movie_index].availableSeats[date_index].seats[round_index][col]= false;
                     break;
                }
            }
    }

}

void saveData(const vector<Movie>& movies, const string& filename) {
    ofstream outFile(filename);
    if (!outFile.is_open()) {
        cout << "Error opening file for writing: " << filename << endl;
        return;
    }

    for (const Movie& movie : movies) {
        outFile << movie.title << endl;
        for (size_t i = 0; i < movie.date.size(); i++) {
            outFile << movie.date[i] << endl;
            for (const vector<bool>& row : movie.availableSeats[i].seats) {
                for (bool seat : row) {
                    outFile << (seat ? '1' : '0');
                }
                outFile << endl;
            }
        }
        outFile << endl;
    }

    outFile.close();
    cout << "Data saved successfully." << endl;
}

void loadData(vector<Movie>& movies, const string& filename) {
    ifstream inFile(filename);
    if (!inFile.is_open()) {
        cout << "Error opening file for reading: " << filename << endl;
        return;
    }

    movies.clear();
    string line;
    while (getline(inFile, line)) {
        Movie movie;
        movie.title = line;

        while (getline(inFile, line) && !line.empty()) {
            movie.date.push_back(line);
            Seat seat;
            seat.date = line;
            vector<vector<bool>> seats(4, vector<bool>(10, false));
            for (int i = 0; i < 4; ++i) {
                getline(inFile, line);
                for (size_t j = 0; j < line.size(); ++j) {
                    if (line[j] == '1') {
                        seats[i][j] = true;
                    }
                }
            }
            seat.seats = seats;
            movie.availableSeats.push_back(seat);
        }

        movies.push_back(movie);
    }

    inFile.close();
}

int main() {
    vector<Movie> movies;

    loadData(movies, "reservations.txt");

    string input;
    while (true) {
        cout << "1. View Schedule\n"
             << "2. Make Reservation\n"
             << "3. Save Data\n"
             << "4. Exit\n"
             << "Enter choice: ";
        cin >> input;

        if (input == "1") {
            displaySchedule(movies);
        } else if (input == "2") {
            makeReservation(movies);
        } else if (input == "3") {
            saveData(movies, "reservations.txt");
        } else if (input == "4") {
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}

// Poor Things
// 2024-03-01
// 1111100000
// 1111100000
// 1111100000
// 1111100000
// 2024-03-02
// 1111100000
// 1111100000
// 1111100000
// 1111100000
// 2024-03-03
// 1111100000
// 1111100000
// 1111100000
// 1111100000

// Lord of The Rings
// 2024-03-01
// 1111100000
// 1111100000
// 1111100000
// 1111100000
// 2024-03-02
// 1111100000
// 1111100000
// 1111100000
// 1111100000
// 2024-03-03
// 1111100000
// 1111100000
// 1111100000
// 1111100000

// 4KingsII
// 2024-03-01
// 0000100000
// 1111100000
// 1111100000
// 1111100000
// 2024-03-02
// 1111100000
// 1111100000
// 1111100000
// 1111100000
// 2024-03-03
// 1111100000
// 1111100000
// 1111100000
// 1111100000
