// https://projecteuler.net/problem=47

#include <iostream>
#include <unordered_set>
#include <vector>
#include <utility>
using namespace std;

// the commented codes are to get the prime factors
// commented it because it's significantly slower

// vector<int> factorize(int num, unordered_set<int> primes) {
//   vector<int> factors;
//   int current = num;
//   for (auto prime : primes) {
//     while (current % prime == 0) {
//       current /= prime;
//       factors.push_back(prime);
//     }
//   }

//   return factors;
// }

// int countDistinctFactors(vector<int> factors) {
//   unordered_set<int> distinctFactors;
//   for (auto f : factors) {
//     distinctFactors.insert(f);
//   }

//   return distinctFactors.size();
// }

int countDistinctFactors2(int num, unordered_set<int> &primes) {
  unordered_set<int> factors;
  int current = num;
  for (auto prime : primes) {
    while (current % prime == 0) {
      current /= prime;
      factors.insert(prime);
    }
  }

  return factors.size();
}

int main() {
  unordered_set<int> primes;
  primes.insert(2);
  primes.insert(3);
  primes.insert(5);
  primes.insert(7);

  // store 4 items
  //    number: factors
  // vector<pair<int, vector<int>>> result;
  int currentCount = 0;

  for (int i = 9; i < 1000000; i++) {
    if (i % 10000 == 0) {
      cout << i << endl;
    }

    bool isPrime = true;
    for (auto prime : primes) {
      if (i % prime == 0) {
        isPrime = false;
      }
    }
    if (isPrime) {
      primes.insert(i);
      // result.clear();
      currentCount = 0;
      continue;
    }

    if (countDistinctFactors2(i, primes) == 4) {
      currentCount++;
      if (currentCount == 4) {
        cout << i-3 << endl;
        return 0;
      }
    } else {
      currentCount = 0;
    }

    // vector<int> factors = factorize(i, primes);
    // int distinctFactors = countDistinctFactors(factors);
    // if (distinctFactors == 4) {
    //   result.push_back(make_pair(i, factors));
    //   if (result.size() == 4) {
    //     for (auto item : result) {
    //       cout << item.first << ": ";
    //       for (auto factor : item.second) {
    //         cout << factor << " * ";
    //       }
    //       cout << endl;
    //     }
    //     return 0;
    //   }
    // } else {
    //   result.clear();
    // }
  }
  return 0;
}
