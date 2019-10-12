#include <map>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  map<int, int> nextExpectedNumberCountPair;
  int difference = 2;

  vector<int> arr;

  arr.push_back(1);
  arr.push_back(3);
  arr.push_back(5);
  arr.push_back(7);
  arr.push_back(7);

  for (vector<int>::iterator it = begin(arr); it != arr.end(); it++) {
    int number = *it;
    int nextExpectedNumber = number + difference;
    if (nextExpectedNumberCountPair.find(number) == nextExpectedNumberCountPair.end()) {
      if (nextExpectedNumberCountPair.find(nextExpectedNumber) == nextExpectedNumberCountPair.end()) {
        nextExpectedNumberCountPair[nextExpectedNumber] = 1;
      }
    } else {
      nextExpectedNumberCountPair[nextExpectedNumber] = nextExpectedNumberCountPair[number] + 1;
      if (difference != 0) {
        nextExpectedNumberCountPair.erase(number);
      }
    }

    cout << number << endl;
    for (map<int, int>::iterator it = nextExpectedNumberCountPair.begin(); it != nextExpectedNumberCountPair.end(); it++) {
      cout << it->first << " " << it->second << endl;
    }
    cout << endl;
  }

  int currentMax = 1;

  for (map<int, int>::iterator it = nextExpectedNumberCountPair.begin(); it != nextExpectedNumberCountPair.end(); it++) {
    if (it->second > currentMax) {
      currentMax = it->second;
    }
  }
  cout << currentMax << endl;
  return currentMax;
}
