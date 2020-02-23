// https://codeforces.com/problemset/problem/1307/B

#include <iostream>
#include <set>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t-- > 0) {
    int n, x, num;

    cin >> n >> x;
    int max = 0;
    set<int> numbers;
    while (n-- > 0) {
      cin >> num;
      if (num > max) {
        max = num;
      }
      numbers.insert(num);
    }

    int result;
    // case 1: exact favourite number
    if (numbers.find(x) != numbers.end()) {
      result = 1;
    } else {
      // case 2: 2 steps with isosceles triangle
      if (x < max) {
        result = 2;
      } else {
        // case 3: keep walking largest number. if the distance is not multiply of max, walk isosceles triangle in second last step
        result = x / max;
        int remainder = x % max;
        if (remainder != 0) {
          result++;
        }
      }
    }

    cout << result << endl;
  }
  return 0;
}
