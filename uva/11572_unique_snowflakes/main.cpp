#include <iostream>
#include <string>
#include <map>

int main() {
    int numTest;
    scanf("%i", &numTest);
    for (int i = 0; i < numTest; i++) {
        int n;
        scanf("%i", &n);
        
        std::map<std::string, int> idIndexPair;
        int currentStart = 0;
        int currentMax = 0;
        for (int j = 0; j < n; j++) {
            std::string input;
            std::cin >> input;

            if (idIndexPair.find(input) != idIndexPair.end()) {
                if (idIndexPair[input] >= currentStart) {
                    currentStart = idIndexPair[input] + 1;
                }
            }
            int length = j - currentStart + 1;
            if (length > currentMax) {
               currentMax = length;
            }
            idIndexPair[input] = j;
        }           
        std::cout << currentMax << std::endl;
    }
    return 0;
}
