#include<iostream>
#include<iomanip>
#include<sstream>
#include<locale>
using namespace std;

string formatNumber(long long int number) {
    stringstream ss;
    ss.imbue(locale(""));
    ss << fixed << number;
    return ss.str();
}

class PopulationGrowth {
    private:
        double initialPopulation;
        double annualGrowthRate;
        double annualIncrease;

    public:
        PopulationGrowth(double initialPop, double growthRate) {
            initialPopulation = initialPop;
            annualGrowthRate = growthRate;
            annualIncrease = 0.0;
        }

        void calculateGrowthForYears(int years) {
            double population = initialPopulation;
            cout << setw(8) << "Year" << setw(25) << "Projected Population" << setw(20) << "Annual Increase" << endl;
            cout << setprecision(0) << fixed;
            for (int year = 1; year <= years; ++year) {
                double increase = population * (annualGrowthRate / 100.0);
                annualIncrease = increase;
                population += increase;
                cout << setw(8) << formatNumber(year) << setw(25) << formatNumber(population) << setw(20) << formatNumber(increase) << endl;
            }
        }

        int findDoublingYear() {
            double population = initialPopulation;
            int year = 0;
            while (population < initialPopulation * 2) {
                double increase = population * (annualGrowthRate / 100.0);
                population += increase;
                year++;
            }
            return year;
        }

        double getAnnualIncrease() const {
            return annualIncrease;
        }
};

int main() {
    double currentPopulation, growthRate;

    cout << "Enter the current world population: ";
    cin >> currentPopulation;

    cout << "Enter the annual growth rate (percentage): ";
    cin >> growthRate;

    PopulationGrowth population(currentPopulation, growthRate);

    int numYears = 75; // Number of years to calculate population growth
    cout << "Population growth for " << numYears << " years:" << endl;
    population.calculateGrowthForYears(numYears);

    int doublingYear = population.findDoublingYear();
    if (doublingYear > 0) {
        cout << "The population is projected to double its initial size in Year " << doublingYear << "." << endl;
    } else {
        cout << "The population is not projected to double its initial size within 75 years." << endl;
    }
    return 0;
}
