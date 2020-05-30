#include <iostream>
#include <string>
using namespace std;

int main() {
  int t, n;

  cin >> t;
  while (t-- > 0) {
    cin >> n;
    string lines[1000];

    for (int i = 0; i < n; i++) {
      string line;
      cin >> line;
      lines[i] = line;
    }

    bool isValid = true;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (lines[i][j] == '0') {
          continue;
        }

        if (i == n - 1 || j == n - 1) {
          continue;
        }
        if (lines[i+1][j] == '1') {
          continue;
        }
        if (lines[i][j+1] == '1') {
          continue;
        }
        isValid = false;
      }
    }

    if (isValid) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }

  return 0;
}
