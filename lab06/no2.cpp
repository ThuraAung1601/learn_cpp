#include<iostream>
using namespace std;

enum class Answer {A, B, C}; 

class QuizQuestion {
    string question;
    string choices[3];
    Answer correctAnswer;
    public:

    QuizQuestion(string q, string c1, string c2, string c3, Answer ans)
        : question(q), correctAnswer(ans) { 
            choices[0] = c1; choices[1] = c2; choices[2] = c3;
        } 
    
    void displayQuestion(int counter) {
        cout << "Question " << counter+1 << " :" << question << endl;
        cout << "a)" << choices[0] << endl;
        cout << "b)" << choices[1] << endl;
        cout << "c)" << choices[2] << endl;
    }

    bool checkAnswer(char ch, Answer userAns) const {
        switch (ch) {
            case 'a':
                userAns = Answer::A;
                break;
            case 'b':
                userAns = Answer::B;
                break;
            case 'c':
                userAns = Answer::C;
                break;
            default:
                cout << "Invalid input. Please enter a, b, or c." << endl;
                cout << "Your answer (a, b, c): "; cin >> ch;
                checkAnswer(ch, userAns);         
        }
        if (userAns == correctAnswer) {
            return true;
        } else {
            return false;
        }
    }
};

int main() {
    QuizQuestion questions[] = {
        QuizQuestion("What is the capital of France?", "Berlin", "Paris", "London", Answer::B),
        QuizQuestion("Which planet is known as the Red Planet?", "Mars", "Jupiter", "Saturn", Answer::A),
        QuizQuestion("What is the largest mammal?", "Elephant", "Blue Whale", "Giraffe", Answer::B),
        QuizQuestion("Who wrote 'Hamlet'?", "Mark Twain", "Charles Dickens", "William Shakespeare", Answer::C),
        QuizQuestion("What is the chemical symbol for water?", "H2O", "CO2", "O2", Answer::A)
    };

    int counter = 0; int score = 0;
    int total_number_of_questions = 5;
    cout << total_number_of_questions;
    while (counter <= total_number_of_questions-1) {
        questions[counter].displayQuestion(counter);
        char ch;
        cout << "Your answer (a, b, c): "; cin >> ch;
        Answer userAns;
        // cout << questions[counter].checkAnswer(ch, userAns) << endl;
        if (questions[counter].checkAnswer(ch, userAns)) {
            cout << "Correct !" << endl; score++;
        } else {
            cout << "Wrong" << endl;
        }
        counter++;
    }
    cout << "Your total score is " << score << endl;
    return 0;
}
