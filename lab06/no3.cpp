#include<iostream>
using namespace std;

int mystery(int, int);

int main() {
    int x = 0; int y = 0;
    cout << "Enter two integers: " << endl; cin >> x >> y;
    cout << "The result is " << mystery(x, y) << endl;
    return 0;
}

// int mystery(int a, int b) {
//     if (b == 1) {
//         return a;
//     } else {
//         // it just muliply a with b
//         // - at each call a is added to a and go on 
//         return a + mystery(a, b-1);
//     }
// }

int mystery(int a, int b) {
    if (b == 1) {
        return a;
    } else if (b == 0) {
        return 0;
    } else if (b < 0) {
        throw invalid_argument("Invalid second integer!!!");
        //cout << "Invalid second integer!!!";
        //return 1;
    }
    else {
        // it just muliply a with b
        // - at each call a is added to a and go on 
        return a + mystery(a, b-1);
    }
}
