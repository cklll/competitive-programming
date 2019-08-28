#include <iostream>
using namespace std;

int main() {
    int numTests;
    cin >> numTests;

    while (numTests--) {
        int n, k;
        cin >> n >> k;
        cout << (k ^ (k >> 1)) << endl;
    }

    return 0;
}

// 0 => 0
// 1 =>  1
// 2 =>  3
// 3 =>  2
// 4 =>  6
// 5 =>  7
// 6 =>  5
// 7 =>  4

// 0 => 0^0 =>
// 0

// 1 1^0
// 1

// 10 10^1
// 11

// 11 11^01
// 10

// 100 100^010
// 110

// 101 101^010
// 111

// 110
// 101

// 111
// 100
