// https://onlinejudge.org/external/112/11286.pdf

#include <stdio.h>
#include <iostream>
#include <map>
#include <string>
#include <algorithm>

int main() {
  int n;
  while ((std::cin >> n) && n != 0) {
    std::map<std::string, int> countsByCombination;

    int maxCombinationCount = 0;
    for (int i = 0; i < n; i++ ){
      int c1, c2, c3, c4, c5;
      scanf ("%d %d %d %d %d", &c1, &c2, &c3, &c4, &c5);

      int courses[5] = { c1, c2, c3, c4, c5 };

      std::sort(std::begin(courses), std::end(courses));
      // std::cout << courses[0] << std::endl;

      std::string hashKey = std::to_string(courses[0]) + "," + std::to_string(courses[1]) + "," + std::to_string(courses[2]) + "," + std::to_string(courses[3]) + "," + std::to_string(courses[4]);

      countsByCombination[hashKey]++;

      if (countsByCombination[hashKey] > maxCombinationCount) {
        maxCombinationCount = countsByCombination[hashKey];
      }
    }

    // if 2 courses have same number of people
    // we need to count twice
    int finalCount = 0;
    for (auto const& pair : countsByCombination) {
      if (pair.second == maxCombinationCount) {
        finalCount += maxCombinationCount;
      }
    }

    std::cout << finalCount << std::endl;
  }
  return 0;
}
