#include <iostream>
#include <vector>
using namespace std;

// ======================= Pokemon Class Family ================== //

class Pokemon {
    protected:
        string name, sound, type; int power; int speed;
    public:
        Pokemon (string n, string snd, string t, int p, int s) {
            name = n;
            sound = snd;
            type = t;
            power = p;
            speed = s;
        }
        string get_name() const { return name; } 
        string get_sound() const { return sound; }
        string get_type() const { return type; }
        int get_power() const { return power; }
        int get_speed() const { return speed; }
};

class WildPokemon: public Pokemon {
    private:
            int catchRate;
    public:
            WildPokemon(string n, string snd, string t, int p, int s, int cRate) : Pokemon(n, snd, t, p, s) {
                catchRate = cRate;
            }
    
            int get_catchRate() const {
                return catchRate;
            }

            void attemptEscape() const {
                cout << name << " escaped." << endl;
            }
};

class PalPokemon : public Pokemon {
    // inherits all attributes from Pokemon
    // Represents a Pokemon that has been caught and is now companion
};

// ===================== Pokeball class ========================== //

class Pokeball {
    public:
            string name; int efficiency;
            Pokeball(string n, int eff) {
                name = n; efficiency = eff;
            }

            void catchPokemon(WildPokemon wild_pk, bool condition) {
                // Attempted to catch Pokemon
                if (condition) {
                    cout << "Caught " <<  wild_pk.get_name() << " !" << endl;
                    cout << "The player successfully caught a Pokemon." << endl;
                }
                else {
                    wild_pk.attemptEscape();
                    cout << "The Pokemon escaped." << endl;
                }
            }

            string get_name() const {
                return name;
            }

            int get_efficiency() const {
                return efficiency;
            }
};

// ===================== Berry class ========================== //

class Berry {
    private:
            string name; int effectiveness;
    public:
            Berry(string n, int effective) {
                name = n; effectiveness = effective;
            }

            void applyEffect(Pokeball& p_ball) {
                // Pokeball power enhanced
                // or make a wild pokemon easier to catch
                p_ball.efficiency += effectiveness;
            }
};

// ===================== Player class ========================== //

class Player {
    // private:
            // vector<Pokeball> ball_collection;
    //         // Optional Berry
    public:
            vector<Pokeball> ball_collection; 
            // Optional Berry 
            Player(vector<Pokeball> ball_ls) {
                ball_collection = ball_ls;
            }

            void addBall(Pokeball pb) {
                ball_collection.push_back(pb);
            }

            // Method to attempt catching a Pokemon
            void catchPokemon(WildPokemon& pokemon) {
                
            }
};

// ===================== World class ========================== //

class World {
    public:
            vector<WildPokemon> wild_collection;
            World(vector<WildPokemon> wild_ls) {
                wild_collection = wild_ls;
            }
            void simulatePlayer() {
                // method to simulate player
            }
};

// ===================== GameTester class ========================== //

class GameTester {
    // static methods to run tests for different game functionalities
    static void test_catch_mechanism() {
        WildPokemon poke1 ("Pidgey", "-", "-", 80, 100, 50);
        cout << "Enconter a " << poke1.get_name() << " !" << endl;
        Pokeball pBall1("Ultra", 30);
        pBall1.catchPokemon(poke1, true);
    }

    static void test_escape_mechanism() {
        WildPokemon poke1 ("Abra", "-", "-", 80, 100, 50);
        cout << "Enconter a " << poke1.get_name() << " !" << endl;
        Pokeball pBall1("Ultra", 30);
        pBall1.catchPokemon(poke1, false);
    }

    public:
        static void runAllTests() {
            cout << "Testing Catch Mechanics:" << endl;
            test_catch_mechanism();
            cout << "------------" << endl;
            cout << "Testing Escape Mechanics:" << endl;
            test_escape_mechanism();
        }
};

// ===================== main function ========================== //

int main() {
    GameTester::runAllTests();
    return 0;
}
