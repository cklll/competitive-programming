#include <iostream>
#include <iomanip>
#include <string>
#include <map>
using namespace std;

// NOTES:
// The elements in std::map are ordered (by default) by operator< applied to the key.

int main() {
  int n;
  scanf("%d\n", &n);

  while (n-- > 0) {
      string name;

      std::map<std::string, int> countPair;
      int total = 0;
      while(std::getline(std::cin, name) && name != "") {
        countPair[name]++;
        total++;
      }
      
      double dTotal = (double) total;
      for(std::map<std::string, int>::iterator iter = countPair.begin(); iter != countPair.end(); iter++) {
          std::cout << iter->first << " " << std::setprecision(4) << std::fixed << (iter->second / dTotal * 100) << std::endl;
      }
      if (n > 0) {
        std::cout << std::endl;
      }
  }
  return 0;
}
