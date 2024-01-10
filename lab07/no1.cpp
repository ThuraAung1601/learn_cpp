// Author: Yaenin Saema, Nay Chi Shunn Lei

#include<iostream>
#include<limits>
#include<iomanip>

const int numDishes = 5;
const int numPolls = 5;

std::string dishes[] = {"Pad Thai", "Som Tam", "Mango Sticky Rice", "Tom Yum Goong", "Green Curry"};

int responses[numDishes][10] = {0};

void collectRatings() {
    for (int i = 0; i<numPolls; i++) {
        std::cout << "\nPoll " << i+1 << ":\n";
        for (int dish = 0; dish < numDishes; dish++) {
            int rating;
            do {
                std::cout << "Rate " << dishes[dish] << " on a scale of 1 to 10: ";
                std::cin >> rating;
                if (rating < 1 || rating > 10 || std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                    rating = -1;
                } 
            } while (rating == -1);

            responses[dish][rating - 1]++;
        }
    }

}

void displayResults() {
    std::cout << "Survey Results" << std::endl;
    std::cout <<  "Dish" << std::setw(10) ;

    for (int i=0; i<10;i++) {
        std::cout << i+1 << "     ";
    }
    std::cout << "Average";
    std::cout << std::endl;

    int highestTotal = 0, lowestTotal = numPolls * numDishes, highestIndex = 0, lowestIndex = 0;

    for (int dish=0; dish < numDishes; dish++){
        std::cout <<  dishes[dish] << std::setw(10) ;
        double total = 0.0;
        for (int rating = 0; rating < 10; rating++) {
            std::cout << responses[dish][rating] << std::setw(5);
            total += (rating + 1) * responses[dish][rating];
        }
        double average = total / (numPolls * 1.0);
        std::cout << average << "\n";

        if (total > highestTotal) {
            highestTotal = total;
            highestIndex = dish;
        }
        if (total < lowestTotal) {
            lowestTotal = total;
            lowestIndex = dish;
        }
    }

    std::cout << "\nHighest rated dish: " << dishes[highestIndex] << " (score: " << highestTotal << ")\n";
    std::cout << "Lowest rated dish: " << dishes[lowestIndex] << " (score: " << lowestTotal << ")\n";
}

int main() {
    collectRatings();
    displayResults();
    return 0;
}
