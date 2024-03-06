#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

class Mapper {
    public:
        std::vector<std::pair<std::string, int> > map(const std::string& line) {
            std::vector<std::pair<std::string, int> > wordCounts;
            std::string word;
            size_t pos = 0, found;
            while ((found = line.find_first_of(" \t", pos)) != std::string::npos) {
                word = line.substr(pos, found - pos);
                if (!word.empty()) {
                    wordCounts.push_back(std::make_pair(word, 1));
                }
                pos = line.find_first_not_of(" \t", found);
            }
            if (pos != std::string::npos) {
                word = line.substr(pos);
                if (!word.empty()) {
                    wordCounts.push_back(std::make_pair(word, 1));
                }
            }
            return wordCounts;
        }
};

class Reducer {
public:
    std::vector<std::pair<std::string, int> > reduce(std::vector<std::pair<std::string, int> >& wordPairs) {
        std::sort(wordPairs.begin(), wordPairs.end()); // Sort the word pairs by key
        std::vector<std::pair<std::string, int> > reducedPairs;
        if (!wordPairs.empty()) {
            reducedPairs.push_back(wordPairs[0]);
            for (size_t i = 1; i < wordPairs.size(); ++i) {
                if (wordPairs[i].first == reducedPairs.back().first) {
                    reducedPairs.back().second += wordPairs[i].second; // Aggregate counts for the same word
                } else {
                    reducedPairs.push_back(wordPairs[i]);
                }
            }
        }
        return reducedPairs;
    }
};

int main() {
    // Prompt the user to enter the name of the text file
    std::cout << "Enter the name of the text file: ";
    std::string filename;
    std::cin >> filename;

    // Open the input file
    std::ifstream inputFile(filename.c_str());

    // Check if the file is opened successfully
    if (!inputFile.is_open()) {
        std::cerr << "Error: File not found." << std::endl;
        return 1;
    }

    // Process the file content using Mapper
    Mapper mapper;
    std::vector<std::pair<std::string, int> > mappedPairs;
    std::string line;
    while (std::getline(inputFile, line)) {
        std::vector<std::pair<std::string, int> > wordCounts = mapper.map(line);
        mappedPairs.insert(mappedPairs.end(), wordCounts.begin(), wordCounts.end());
    }

    // Close the input file
    inputFile.close();

    // Reduce phase
    Reducer reducer;
    std::vector<std::pair<std::string, int> > reducedPairs = reducer.reduce(mappedPairs);

    // Display word counts on the screen
    for (const std::pair<std::string, int>& pair : reducedPairs) {
        std::cout << pair.first << " " << pair.second << std::endl;
    }

    // Save word counts to the output file with "_mr" suffix
    size_t dotPos = filename.find_last_of('.');
    std::string outputFilename = filename.substr(0, dotPos) + "_mr.txt";
    std::ofstream outputFile(outputFilename.c_str());
    if (!outputFile.is_open()) {
        std::cerr << "Error: Unable to create output file." << std::endl;
        return 1;
    }
    for (const std::pair<std::string, int>& pair : reducedPairs) {
        outputFile << pair.first << " " << pair.second << std::endl;
    }
    outputFile.close();

    std::cout << "Word counts saved to " << outputFilename << std::endl;

    return 0;
}
