#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

class GuessNumberGame {
    private: 
        int number_of_tries;
        int maximum_tries;
        int number_to_guess;

    public:
        GuessNumberGame() : maximum_tries(10), number_of_tries(0) {
            srand(time(nullptr));
            number_to_guess = rand() % 101;
        }

        void play() {
            int guess;
            cout << "Guess the number (between 0 and 100): ";

            while (number_of_tries < maximum_tries) {
                cin >> guess;
                number_of_tries++;

                if (guess == number_to_guess) {
                    cout << "Congratulations! You win." << endl;
                    return;
                } else if (guess < number_to_guess) {
                    cout << "Higher than your number. Try again: ";
                } else {
                    cout << "Lower than our number. Try again: ";
                }
            }

            cout << "You lose. The number was " << number_to_guess << "." << endl;
        }
};

int main() {
    GuessNumberGame game;
    game.play();
    return 0;
}
