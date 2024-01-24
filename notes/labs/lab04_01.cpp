#include<iostream>
#include<vector>
#include<list>
using namespace std;

template<typename T1>
void print_collection(T1 v) {
    for (const auto &i : v) {
        cout << i << " ";
    }
    cout << endl;
}

template<typename T2>
vector<T2> lshift(vector<T2> shifted, int num) {
    if (shifted.size() < num) {
        shifted.clear();
    } else {
        shifted.erase(shifted.begin(), shifted.begin()+num);
    }
    return shifted;
}

template<typename T2>
vector<T2> rshift(vector<T2> shifted, int num) {
    shifted.insert(shifted.begin(), num, 0);
    return shifted;
}

template<typename T3>
list<T3> remove_neg(list<T3> ls) {
    ls.remove_if([](T3 n) {return n < 0; });
    return ls;
}

// function overloading
template<typename T3>
vector<T3> remove_neg(vector<T3> ls) {
    for (size_t i=0; i<ls.size();) {
        if (ls[i] < 0) {
            ls.erase(ls.begin()+i);
        } else {
            ++i;
        }
    }
    return ls;
}

int main() {
    vector<int> v1 = {1, 2, -3, -4, 5, 6, 7};
    vector<int> lshifted = lshift(v1, 3);
    vector<int> rshifted = rshift(v1, 3);
    vector<int> no_neg = remove_neg(v1);

    list<int> l1 = {1, 2, -1, -2, 3, -4, 5};
    list<int> no_neg_ls = remove_neg(l1);

    cout << "Vector" << endl;
    print_collection(v1);
    print_collection(lshifted);
    print_collection(rshifted);    
    print_collection(no_neg);

    cout << "List" << endl;
    print_collection(l1);
    print_collection(no_neg_ls);

    return 0;
}
