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

    // Calculate median
    size_t size = numbers.size();
    size_t middle = size / 2;
    std::nth_element(numbers.begin(), numbers.begin() + middle, numbers.end());
    double median;
    if (size % 2 == 0) {
        std::nth_element(numbers.begin(), numbers.begin() + middle - 1, numbers.end());
        median = (numbers[middle - 1] + numbers[middle]) / 2.0;
    } else {
        median = numbers[middle];
    }

    // Calculate standard deviation
    double variance = 0.0;
    for (double n : numbers) {
        variance += (n - mean) * (n - mean);
    }
    double stddev = sqrt(variance / numbers.size());

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
