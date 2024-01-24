#include<iostream>
#include<string>
#include<vector>
#include<list>
using namespace std;

void reverser(string &s, size_t index) {
    if (s.length() == index) {
        return ;
    } 
    reverser(s, index+1);
    cout << s[index];
}

void reverser(vector<int> &v1, size_t index) {
    if (v1.size() == index) {
        return;
    }
    reverser(v1, index+1);
    cout << v1[index];
}

void reverser(list<int> &l1, list<int>::iterator i) {
    if (i == l1.end()) {
        return;
    }
    reverser(l1, next(i));
    cout << *i;
}

void reverser(int *ptr, int SIZE) {
    if (SIZE == 0) {
        return;
    }
    reverser(ptr+1, SIZE-1);
    cout << *ptr;
}

int main() {
    string s = "Hello";
    reverser(s, 0);
    
    vector<int> v1 = {1, 2, 3};
    cout << endl;
    reverser(v1, 0);

    list<int> l1 = {1, 2, 3};
    cout << endl;
    reverser(l1, l1.begin());

    int a1[3] = {1, 2, 3};
    cout << endl;
    reverser(a1, 3);
    return 0;
}
