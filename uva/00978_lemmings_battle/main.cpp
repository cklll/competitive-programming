#include <iostream>
#include <set>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    
    while (n-- > 0) {
        std::multiset<int> greenCount;
        std::multiset<int> blueCount;

        int numBattlefield, numGreen, numBlue;
        std::cin >> numBattlefield >> numGreen >>  numBlue;

        for (int i = 0; i < numGreen; i++) {
            int number;
            std::cin >> number;
            greenCount.insert(number);
        }
        for (int i = 0; i < numBlue; i++) {
            int number;
            std::cin >> number;
            blueCount.insert(number);
        }

        while (true) {
            if (blueCount.empty() || greenCount.empty()) {
                break;
            }
            std::vector<int> newGreenNumbers; 
            std::vector<int> newBlueNumbers; 

            for (int i = 0; i < numBattlefield; i++) {
                if (blueCount.empty() || greenCount.empty()) {
                    break;
                }
                
                std::multiset<int>::iterator greenIter = greenCount.end();
                std::multiset<int>::iterator blueIter = blueCount.end();

                greenIter--;
                blueIter--;

                int greenNum = *greenIter;
                int blueNum = *blueIter;
                
                greenCount.erase(greenIter);
                blueCount.erase(blueIter);

                if (greenNum > blueNum) {
                    newGreenNumbers.push_back(greenNum - blueNum);
                } else if (blueNum > greenNum) {
                    newBlueNumbers.push_back(blueNum - greenNum);
                }
            }

            for (std::vector<int>::iterator iter = newGreenNumbers.begin(); iter != newGreenNumbers.end(); iter++) {
                greenCount.insert(*iter);
            }
            for (std::vector<int>::iterator iter = newBlueNumbers.begin(); iter != newBlueNumbers.end(); iter++) {
                blueCount.insert(*iter);
            }
        }

        if (blueCount.empty() && greenCount.empty()) {
            std::cout << "green and blue died" << std::endl;
        } else if (blueCount.empty()) {
            std::cout << "green wins" << std::endl;
            std::multiset<int>::reverse_iterator iter;
            for (iter = greenCount.rbegin(); iter != greenCount.rend(); iter++) {
                std::cout << *iter << std::endl;
            }
        } else if (greenCount.empty()) {
            std::cout << "blue wins" << std::endl;
            std::multiset<int>::reverse_iterator iter;
            for (iter = blueCount.rbegin(); iter != blueCount.rend(); iter++) {
                std::cout << *iter << std::endl;
            }
        }
        

        if (n > 0) {
            std::cout << std::endl;
        }
    }

    return 0;
}
