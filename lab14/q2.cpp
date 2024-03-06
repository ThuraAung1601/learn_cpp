#include <iostream>
#include <vector>

std::string setPrecision(double value, int precision) {
    std::string result = std::to_string(value);
    size_t pos = result.find('.');
    if (pos != std::string::npos && pos + precision + 1 < result.size()) {
        int temp = result[pos+precision+1] - '0';
        // std::cout << value << std::endl;
        // std::cout << temp << std::endl;
        if (temp >= 5) {
            result[pos+precision] += 1;
        }
        result = result.substr(0, pos + precision + 1);
    }
    return result;
}

double findSqrt(double x)
{
    // for 0 and 1, the square roots are themselves
    if (x < 2)
        return x;
 
    // considering the equation values
    double y = x;
    double z = (y + (x / y)) / 2;
 
    // as we want to get upto 5 decimal digits, the absolute
    // difference should not exceed 0.00001
    while (fabs(y - z) >= 0.00001) {
        y = z;
        z = (y + (x / y)) / 2;
    }
    return z;
}

int main() {
    std::vector<double> numbers; // Create a vector to store numbers

    std::cout << "Enter numbers (enter a non-numeric value to finish):" << std::endl;

    double num;
    while (std::cin >> num) {
        // Read numbers until non-numeric value is entered
        numbers.push_back(num);
    }

    if (numbers.empty()) {
        std::cout << "No numbers entered." << std::endl;
        return 0;
    }

    // Calculate mean
    double sum = 0.0;
    for (double n : numbers) {
        sum += n;
    }
    double mean = sum / numbers.size();

    // Calculate medium
    double median;
    size_t size = numbers.size();

    std::vector<double> sortedNumbers = numbers;

    // Bubble sort implementation
    for (size_t i = 0; i < size - 1; ++i) {
        for (size_t j = 0; j < size - i - 1; ++j) {
            if (sortedNumbers[j] > sortedNumbers[j + 1]) {
                // Swap elements if they are in the wrong order
                double temp = sortedNumbers[j];
                sortedNumbers[j] = sortedNumbers[j + 1];
                sortedNumbers[j + 1] = temp;
            }
        }
    }

    if (size % 2 == 0) {
        // If the size of the vector is even, return the average of the two middle elements
        median = (sortedNumbers[size / 2 - 1] + sortedNumbers[size / 2]) / 2.0;
    } else {
        // If the size of the vector is odd, return the middle element directly
        median = sortedNumbers[size / 2];
    }

    // Calculate standard deviation
    double variance = 0.0;
    for (double n : numbers) {
        variance += (n - mean) * (n - mean);
    }
    double stddev = findSqrt(variance / numbers.size());

    // Find minimum and maximum
    double minimum = numbers[0];
    double maximum = numbers[0];
    for (double n : numbers) {
        if (n < minimum) {
            minimum = n;
        }
        if (n > maximum) {
            maximum = n;
        }
    }

    std::cout << "Mean: " << setPrecision(mean, 2) << std::endl;
    std::cout << "Median: " << setPrecision(median, 2) << std::endl;
    std::cout << "Standard Deviation: " << setPrecision(stddev, 2) << std::endl;
    std::cout << "Minimum: " << setPrecision(minimum, 2) << std::endl;
    std::cout << "Maximum: " << setPrecision(maximum, 2) << std::endl;

    return 0;
}
