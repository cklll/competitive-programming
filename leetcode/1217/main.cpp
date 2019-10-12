#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> chips;
  chips.push_back(2);
  chips.push_back(2);
  chips.push_back(2);
  chips.push_back(3);
  chips.push_back(3);

  int odd = 0, even = 0;
  for (vector<int>::iterator it = begin(chips); it != chips.end(); it++) {
    if (*it % 2 == 0) {
      even++;
    } else {
      odd++;
    }
  }

cout << even << " " << odd << endl;
  if (even > odd) {
    return odd;
  } else {
    return even;
  }
}
