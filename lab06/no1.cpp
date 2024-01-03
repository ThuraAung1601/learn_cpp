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

int main() {
    int noi;
    cout << "Enter the number of integers: "; cin >> noi;
    if (noi <= 0) {
        cout << "The number of integers should be positive integer greater than zero" << endl;
        return 1;
    }
    cout << "Enter integers: " << endl;
    vector<int> vec_num;

    for (int i=0; i<noi; i++) {
        int temp; cin >> temp;
        vec_num.push_back(temp);
    }
    cout << "Smallest integer is " << mini(vec_num);
    return 0;
}
