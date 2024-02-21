#include <iostream>
#include <vector>
#include <string>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
using namespace std;

// ======================= Pokemon Class (Base Class) ================== //

class Pokemon {
protected:
    string name, sound, type;
    int power, speed;

public:
    Pokemon(string n, string snd, string t, int p, int s)
        : name(n), sound(snd), type(t), power(p), speed(s) {}

    // Getter methods
    string get_name() const { return name; }
    string get_sound() const { return sound; }
    string get_type() const { return type; }
    int get_power() const { return power; }
    int get_speed() const { return speed; }
};

// ===================== Derived from Pokemon ========================== //

class WildPokemon : public Pokemon {
private:
    int catchRate;

public:
    WildPokemon(string n, string snd, string t, int p, int s, int cRate)
        : Pokemon(n, snd, t, p, s), catchRate(cRate) {}

    // Getter method for catchRate
    int get_catchRate() const { return catchRate; }
};

// ===================== Pokeball Class ========================== //

class Pokeball {
public:
    string name;
    int efficiency;
    Pokeball(string n, int eff) : name(n), efficiency(eff) {}

    // Method to attempt catching a WildPokemon
    bool catchPokemon(const WildPokemon& pokemon) const {
        cout << "Attempting to catch " << pokemon.get_name() << " with " << name << "..." << endl;
        // Simulate capture attempt based on efficiency and power
        if (efficiency >= pokemon.get_power()) {
            cout << "Successfully caught " << pokemon.get_name() << "!" << endl;
            return true; // Capture successful
        } else {
            cout << "Failed to catch " << pokemon.get_name() << "." << endl;
            return false; // Capture failed
        }
    }

    // Getter methods
    string get_name() const { return name; }
    int get_efficiency() const { return efficiency; }
};

// ===================== Berry Class ========================== //

class Berry {
private:
    string name;
    int effectiveness;

public:
    Berry(string n, int effective) : name(n), effectiveness(effective) {}

    // Method to apply effect
    void applyEffect(Pokeball& pokeball) const {
        cout << "Applying effect of " << name << " to " << pokeball.get_name() << "..." << endl;
        // Add logic here to enhance efficiency or make wild Pokemon easier to catch
        pokeball.efficiency += effectiveness;
    }

    // Getter methods
    string get_name() const { return name; }
    int get_effectiveness() const { return effectiveness; }
};

// ===================== Player Class ========================== //

class Player {
private:
    vector<Pokeball> ball_collection;
    vector<WildPokemon> captured_pokemons;
    Berry* berry;

public:
    Player() : berry(nullptr) {} // Default constructor

    // Method to add Pokeball to the collection
    void addBall(const Pokeball& pb) {
        ball_collection.push_back(pb);
    }

    // Method to stockpile Pokéballs
    void stockpilePokeballs() {
        // Add five Pokéballs of random types to the inventory
        for (int i = 0; i < 5; ++i) {
            int randType = rand() % 3; // Generate random number between 0 and 2
            string pokeballType;
            int efficiency;
            if (randType == 0) {
                pokeballType = "Normal";
                efficiency = 30;
            } else if (randType == 1) {
                pokeballType = "Strong";
                efficiency = 50;
            } else {
                pokeballType = "Ultra";
                efficiency = 70;
            }
            Pokeball pb(pokeballType, efficiency);
            addBall(pb);
        }
        cout << "Stockpiled five Pokéballs of random types!" << endl;
    }

    // Method to attempt catching a wild Pokemon
    bool exploreAndEncounter(const WildPokemon& pokemon) {
        srand(time(nullptr));
        cout << "Exploring the virtual world..." << endl;
        int randNum = rand() % 4; // Generate random number between 0 and 3
        if (randNum == 0) {
            cout << "Encountered a wild " << pokemon.get_name() << "!" << endl;
            attemptCapture(pokemon);
            return true;
        } else {
            cout << "No wild Pokemon encountered." << endl;
            return false;
        }
    }

    // Method to attempt capturing a wild Pokemon
    void attemptCapture(const WildPokemon& pokemon) {
        if (!ball_collection.empty()) {
            Pokeball selected_ball = ball_collection.back(); // Choose the last ball
            bool success = selected_ball.catchPokemon(pokemon);
            if (success) {
                captured_pokemons.push_back(pokemon); // Add to captured Pokemons if successful
                ball_collection.pop_back();
            }
        } else {
            cout << "No Pokeballs available!" << endl;
        }
    }

    // Method to review current assortment of Pokeballs
    void reviewInventory() const {
        cout << "Current assortment of Pokeballs:" << endl;
        for (const Pokeball& ball : ball_collection) {
            cout << "Name: " << ball.get_name() << ", Efficiency: " << ball.get_efficiency() << endl;
        }
    }

    // Method to access the list of captured Pokemons
    void showCapturedPokemons() const {
        cout << "List of captured Pokemons:" << endl;
        for (const WildPokemon& pokemon : captured_pokemons) {
            cout << pokemon.get_name() << endl;
        }
    }

    // Method to set Berry
    void setBerry(Berry* b) {
        berry = b;
    }

    // Method to apply Berry effect
    void applyBerryEffect(Pokeball& pokeball) const {
        if (berry != nullptr) {
            berry->applyEffect(pokeball);
        }
    }
};

// ===================== World Class ========================== //

class World {
private:
    vector<WildPokemon> wild_collection;

public:
    World(vector<WildPokemon> wild_ls) {
        wild_collection = wild_ls;
    }

    // Method to add WildPokemon to the world
    void addWildPokemon(const WildPokemon& pokemon) {
        wild_collection.push_back(pokemon);
    }

    // Method to simulate player exploration and encounters with wild Pokemon
    void simulatePlayer(Player& player) {
        if (!wild_collection.empty()) {
            bool encountered = player.exploreAndEncounter(wild_collection.back()); // For simplicity, choose the last Pokemon
            if (encountered) wild_collection.pop_back(); // Remove the encountered Pokemon from the world
        }
        else {
            cout << "No more wild Pokemon in the world." << endl;
        }
    }
};

// ===================== Main Function ========================== //

int main() {
    // Seed the random number generator with current time
    srand(time(nullptr)); 

    vector<WildPokemon> wild_ls = {
        WildPokemon("Pikachu", "Pika", "Electric", 60, 30, 50),
        WildPokemon("Charmander", "Char", "Fire", 70, 20, 40),
        WildPokemon("Bulbasaur", "Bulba", "Grass", 75, 100, 35),
        WildPokemon("Snorlax", "Snore", "Normal", 90, 20, 20)
    };

    World world(wild_ls);

    // world.addWildPokemon(WildPokemon("Squirtle", "Squirt", "Water", 65, 80, 45));

    // for (auto i: wild_ls) {
    //     cout << i.get_name() << endl;
    // }

    // Create a player
    Player player;

    // // Enable player to stockpile Pokeballs
    // player.stockpilePokeballs();

    bool condition = true;

    do {
        cout << "Choose an action: \n" 
            << "1. Add Pokeballs to stock \n" 
            << "2. Walk \n" 
            << "3. List PokeBalls \n"
            << "4. List caught Pokemon \n"
            << "5. Exit" << endl;

        int choice;
        cin >> choice;
        bool one_time = true;
        switch (choice) {
            case 1: if(one_time) {player.stockpilePokeballs(); one_time = false;} else {cout << "Not available anymore !!!";} break;
            case 2: world.simulatePlayer(player); break;
            case 3: player.reviewInventory(); break;
            case 4: player.showCapturedPokemons(); break;
            case 5: condition = false; break;
            default: cout << "Invalid Condition!"; break;
        }
    } while (condition);

    return 0;
}
