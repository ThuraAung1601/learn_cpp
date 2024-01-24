#include<iostream>
#include<vector>

std::pair<int, int> min_max_finder(std::vector<int> v1) {
    int max = v1[0];
    int min = v1[0];
    for (int i=0; i < v1.size(); i++) {
        if (max < v1[i]) {
            max = v1[i];
        } 
        if (min > v1[i]) {
            min = v1[i];
        }
        else {
            continue;
        }
    }
    return std::make_pair(min, max);
}

int maxFinder(int *a1, size_t SIZE) {
    if (SIZE == 0) {
        return 0;
    }
    int *max = (*a1 > *(a1+1)) ? a1 : a1+1;
    int recursiveMax = maxFinder(a1+1, SIZE-1);
    return (*max > recursiveMax) ? *max : recursiveMax;;
}

int maxFinder(int a[], size_t start, size_t end) {
    if (start == end) {
        return a[start];
    }
    size_t mid = (start+end)/2;
    int max1 = maxFinder(a, start, mid);
    int max2 = maxFinder(a, mid+1, end);
    return (max1 > max2) ? max1 : max2;
}

int main() {
    std::vector<int> v1 = {1, 100, 2, 200, -200, 221};
    std::pair<int, int> result = min_max_finder(v1);
    std::cout << "Min " << result.first << " Max " << result.second << std::endl;
    int a[4] = {1, 2, 3, 1};
    std::cout << maxFinder(a, 4);
    std::cout << std::endl;
    std::cout << maxFinder(a, 0, 4);
    return 0;
}
