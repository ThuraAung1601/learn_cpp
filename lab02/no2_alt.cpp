// You are given a C++ program that implements a simple number guessing game. The game generates a random
// number between 0 and 100, and the user has to guess what it is. The user is allowed up to 10 guesses. If the
// guess is too low or too high, the program provides feedback. If the user guesses correctly or exhausts all 10
// guesses, the game ends with an appropriate message.
// a. Implement a class GuessNumberGame with the following func=onali=es:
// i. The class should generate a random number between 0 and 100 upon ini=aliza=on.
// ii. Include a method play that contains the game logic.
// b. The main func=on should:
// i. Create an instance of the GuessNumberGame.
// ii. Use a while loop within the play method to allow the user to guess the number un=l they either guess
// correctly or exhaust the maximum number of tries.
// iii. Provide feedback for each guess - indicate whether the actual number is higher or lower than the user's
// guess.
// iv. End the game with a congratulatory message if the user guesses correctly, or inform them of the correct
// number if they lose.
// v. The game should automatically end after a set number of incorrect guesses (e.g., 10 tries).

#include<iostream>
#include<string>
using namespace std;

class GuessNumberGame {
    public:
        int randomNumber;

        // constructor
        GuessNumberGame() {
            // generate a random num between 0 and 100
            randomNumber = rand() % 101; 
            // cout << randomNumber;
        }

    void play() {
        int guess; bool checker = false; int i = 1;
        while (i < 10) {
                cout << "Enter a guess between 0 and 100: "; cin >> guess;
                if (guess < randomNumber) {
                    cout << "Guess is smaller than the number." << endl;
                }
                else if (guess > randomNumber) {
                    cout << "Guess is larger than the number." << endl;
                }
                else {
                    cout << "Congratulations !!!\nYou successfully guessed " << randomNumber << endl;
                    break;
                }
                i++;
                cout << "Sorry. You lose the game to guess " << randomNumber << endl;
        }
    }
};

int main() {
    GuessNumberGame game;
    game.play();
    return 0;
}
