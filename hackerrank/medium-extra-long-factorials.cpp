// https://www.hackerrank.com/challenges/extra-long-factorials/problem

#include <iostream>
#include <vector>
using namespace std;


void extraLongFactorials(int n) {
    vector<int> digits;

    digits.push_back(1);

    for (int i = 2; i <= n; i++) {
        for (auto it = digits.begin(); it != digits.end(); it++) {
            *it *= i;
        }

        for (int j = 0; j < digits.size(); j++) {
            if (digits.at(j) >= 10) {
                int carry = digits.at(j) / 10;
                digits.at(j) = digits.at(j) % 10;

                if (j + 2 > digits.size()) {
                    digits.push_back(carry);
                } else {
                    digits.at(j + 1) += carry;
                }
            }
        }
    }

    // cout << n << "! = ";
    for (auto it = digits.rbegin(); it != digits.rend(); it++) {
        cout << *it;
    }

    cout << endl;

}

int main() {
    
    extraLongFactorials(1);
    extraLongFactorials(2);
    extraLongFactorials(3);
    extraLongFactorials(4);
    extraLongFactorials(5);
    extraLongFactorials(6);
    extraLongFactorials(7);
    extraLongFactorials(25);
    return 0;
}
