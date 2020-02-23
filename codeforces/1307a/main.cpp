#include <iostream>
using namespace std;

// https://codeforces.com/problemset/problem/1307/a

// IN
// 3
// 4 5
// 1 0 3 2
// 2 2
// 100 1
// 1 8
// 0

// OUT
// 3
// 101
// 0

int main() {
  int t, n, d, num;

  cin >> t;

  while (t-- > 0) {
    int result;

    cin >> n >> d;

    cin >> result; // first day

    for (int j = 1; j < n; j++) {
      cin >> num;
      for (int i = 0; i < num; i++) {
        d -= j;
        if (d < 0) {
          break;
        }
        result += 1;
      }
    }

    cout << result << endl;
  }

  return 0;
}
