/* 
    Author: Eaint Kay Khine Kyaw for No 1.1
    Author: Ei Myat Nwe for No 1.2 and 1.3
*/
#include <iostream>
#include <vector>
#include <list>
using namespace std;

void lshift(vector<int>& vec, int num) {
    vec.erase(vec.begin(), vec.begin() +num);
}

void rshift(vector<int>& vec, int num) {
    vec.insert(vec.begin(), num, 0);
}

void remove_negative_vec(vector<double>& vec)
{
   cout << "Original Vector:";
   for ( double x : vec ) cout << x << " ";


   int i = 0;
   while ( i < vec.size() )
   {
      if ( vec[i] < 0 ) {
        vec.erase( vec.begin() + i, vec.begin() + i + 1 );
    }else {
        i++;
    }                   
   }

   cout << "\n" << "Vector after removing negative numbers: ";
   for ( double x : vec ) cout <<  x << " ";
   cout << endl;
}

void remove_negative_list(list<float>& lst){
    cout << "Original List: ";
    for (float x: lst) cout << x << " ";

    auto i = lst.begin();
    while ( i != lst.end()){
        if ( *i < 0){
           i = lst.erase(i);
        }else{
            i++;
        }
    }
    cout << "\n" << "List after removing negative numbers: ";
    for (double x: lst) cout << x << " ";

}

int main(){
    vector<int> myvec = {1,2,3,4,5};

    // no1.1
    lshift(myvec, 2);
    cout << "Left shift: ";
    for (int x: myvec) {
        cout << x << " ";
    }
    cout << endl;

    rshift(myvec, 3);
    cout << "Right shift: ";
    for (int x: myvec) {
        cout << x << " ";
    }
    cout << endl;

    // no1.2 no1.3
    vector<double> vec;
    vec.push_back(0.8);
    vec.push_back(-5.1);
    vec.push_back(1.6);
    vec.push_back(-6.5);
    vec.push_back(10.5);

    list<float> lst;
    lst.push_back(0.8);
    lst.push_back(-5.1);
    lst.push_back(1.6);
    lst.push_back(-6.5);
    lst.push_back(10.5);

    remove_negative_vec(vec);
    remove_negative_list(lst);

    return 0;
}
