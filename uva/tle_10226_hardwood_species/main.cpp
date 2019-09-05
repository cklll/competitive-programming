#include <iostream>
#include <iomanip>
#include <string>
#include <map>
using namespace std;

// NOTES:
// The elements in std::map are ordered (by default) by operator< applied to the key.

int main() {
  int n;
  cin >> n;
  
  while (n--) {
    string line;
    map<string, int> pair;
    int total = 0;
    
    while (getline(cin, line)) {
      if (line == "") {
        for (map<string, int>::iterator i = pair.begin(); i != pair.end(); i++) {
          float percentage = (float)i->second / (float)total * 100.0;
          cout <<  i->first << " " << fixed << setprecision(4) << percentage << endl;
        }
        cout << endl;
        break;
      }

      total++;
      pair[line]++;
    }
  }

  return 0;
}