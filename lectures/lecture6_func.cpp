// lecture 6
// part 3 functions, generic and recursion

#include<iostream>
#include<vector>

using namespace std;

int mini(vector<int> v1) {
    int mini = v1[0];
    for (auto i: v1) {
        if (i < mini) {
            mini = i;
        }
    }
    return mini;
}

vector<int> sorter(vector<int> v1) {
    for (int i=0; i < v1.size(); i++) {
        for (int j=0; j < i; j++) {
            if (v1[j] > v1[j+1]) {
                int temp = v1[j];
                v1[j] = v1[j+1];
                v1[j+1] = temp;
            }
        }
    }
    return v1;
}

template<typename T>
void print(T collection, int size) {
    for (int i=0; i < size; i++) {
        cout << collection[i] << endl;
    }
}

template<typename T>
T mini2(vector<T> v1) {
    T mini = v1[0];
    for (auto i: v1) {
        if (i < mini) {
            mini = i;
        }
    }
    return mini;
}

int main() {
    vector<int> v1 = {1, 3, -3, 21};
    cout << mini(v1) << endl;
    vector<int> sorted = sorter(v1);
    for (auto i: sorted) {
        cout << i << endl;
    }

    vector<string> food1 = {"Apple", "Orange"};
    array<string, 3> food2 = {"Sandwish", "Burger", "Hotdog"};
    string food3[2] = {"Fish", "Chicken"};

    print(food1, food1.size());
    print(food2, 3);
    print(food3, 2);

    vector<int> v2 = {1, 3, -3, 21};
    cout << mini2(v2) << endl;

    vector<float> v3 = {1., 3.5, -3.24, 2.1};
    cout << mini2(v3) << endl;

    return 0;
}