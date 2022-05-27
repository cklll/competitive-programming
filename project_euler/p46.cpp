// https://projecteuler.net/problem=46

#include <cmath>
#include <unordered_set>
#include <iostream>
using namespace std;


bool isPrime(int x) {
  if (x % 2 == 0) {
    return false;
  }

  for (int i = 3; i <= sqrt(x); i+=2) {
    if (x % i == 0) {
      return false;
    }
  }

  return true;
}

int main() {
  unordered_set<int> knownPrimes;
  unordered_set<int> knownNotPrimes;
  knownPrimes.insert(2);
  knownPrimes.insert(3);
  knownPrimes.insert(5);
  knownPrimes.insert(7);

  for (int i = 9; i < 1000000; i+=2) {
    if (isPrime(i)) {
      knownPrimes.insert(i);
      continue;
    } else {
      knownNotPrimes.insert(i);
    }

    // brute force all combinations of 2*square
    int squareRoot = 1;
    int remaining = i - 2 * squareRoot * squareRoot;
    bool found = false;
    while (remaining > 0 && !found) {
      if (knownPrimes.find(remaining) != knownPrimes.end()) {
        // i.e. can be represented
        found = true;
        break;
      }

      squareRoot++;
      remaining = i - 2 * squareRoot * squareRoot;
    }

    if (!found) {
      cout << i << endl;
      // break;
    } else {
      // debug
      // if (i % 1000 == 1) {
      //   cout << i << ": " << remaining << " + " << "2" << "*" << squareRoot << "^2" << endl;
      // }
    }
  }

  return 0;
}
