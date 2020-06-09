#include <iostream>
#include <string>
#include <set>
#include <vector>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t-- > 0) {
    int n, m;
    string strings[10];
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
      string str;
      cin >> str;
      strings[i] = str;
    }

    // brute force
    // for each position, change to a-z
    string result = "";
    for (int i = 0; i < m; i++) {
      bool isValid = true;

      for (int j = 'a'; j <= 'z'; j++) {
        string str = strings[0];
        str[i] = j;
        isValid = true;

        // then compare the resulted string to all other strings
        for (int j = 1; j < n; j++) {
          int diff = 0;
          for (int k = 0; k < m; k++) {
            if (str[k] != strings[j][k]) {
              diff++;
              if (diff > 1) {
                isValid = false;
                break;
              }
            }
          }

          if (!isValid) {
            break;
          }
        }

        if (isValid) {
          result = str;
          break;
        }
      }

      if (isValid) {
        break;
      }
    }

    if (result == "") {
      cout << "-1" << endl;
    } else {
      cout << result << endl;
    }
  }

  return 0;
}
