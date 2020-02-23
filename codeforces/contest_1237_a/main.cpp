// https://codeforces.com/contest/1237/problem/0

#include <iostream>
#include <vector>
using namespace std;

// all round down, then round back up until it's 0

int main() {
  int n;
  vector<int> numbers;
  vector<int> modifiedNumbers;

  int sum = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int number;
    cin >> number;
    int modifiedNumber;

    numbers.push_back(number);
    if (number % 2 == 0) {
      modifiedNumber = number / 2;
    } else {
      if (number > 0) {
        modifiedNumber = number / 2; // round down
      } else {
        modifiedNumber = (number / 2) - 1; // round down
      }
    }
    sum += modifiedNumber;
    modifiedNumbers.push_back(modifiedNumber);
  }

  for (int i = 0; i < n; i++) {
    if (sum == 0) {
      break;
    }
    if (numbers[i] % 2 == 0) {
      continue;
    }
    // must be less than 0
    modifiedNumbers[i]++;
    sum++;
  }

  for (int i = 0; i < n; i++) {
    cout << modifiedNumbers[i] << endl;
  }
  // 2, -2
  // cout << 1 / 2 << -1 / 2 << endl;

  return 0;
}
