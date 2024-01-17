#include<iostream>
#include<vector>
#include<list>

template <typename T1>
vector<T1> delete_neg_vector(vector<T1> vec) {
    for(int i=0; i < vec.size(); i++) {
        if (vec[i] < 0) {
            vec.erase(vec.begin()+i);
        } else {
            continue;
        }
    }
    return vec;
}

template <typename T1>
void delete_neg_vector_ref(vector<T1> &vec) {
    for(int i=0; i < vec.size(); i++) {
        if (vec[i] < 0) {
            vec.erase(vec.begin()+i);
        } else {
            continue;
        }
    }
}

template <typename T2>
list<T2> delete_neg_list(list<T2> ls) {
    for(auto i=ls.begin(); i!=ls.end();) {
        if (*i < 0) {
            i = ls.erase(i);
        } else {
            i++;
        }
    }
    return ls;
}

template <typename T3>
void print_collection(T3 container) {
    for (auto i: container) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    vector<int> v1 = {1, -2, 3, 2, 4, 5};
    vector<int> pos_vec = delete_neg_vector(v1);
    cout << "Original vector: ";
    print_collection(v1);
    cout << "Positive vector: ";
    print_collection(pos_vec);
    cout << "After pass by reference:";
    delete_neg_vector_ref(v1);
    print_collection(v1);

    list<int> l1 = {1, -2, 3, 2, 4, 5};
    list<int> pos_ls = delete_neg_list(l1);
    cout << "Original list: ";
    print_collection(l1);
    cout << "Positive list: ";
    print_collection(pos_ls);
    return 0; 
}
