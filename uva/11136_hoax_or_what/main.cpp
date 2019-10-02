#include <iostream>
#include <set>
#include <string>
#include <sstream>

int main() {
    std::string line;
    int num;
    int numBill;
    int days;

    while (!std::cin.eof() && std::cin >> days) {
        if (days == 0) {
            continue;
        }
        long long result = 0;
        std::multiset<int> pair;
        for (int i = 0; i < days; i++) {
            std::cin >> numBill;
            for (int j = 0; j < numBill; j++) {
                std::cin >> num;
                pair.insert(num);
            }

           std::multiset<int>::iterator iter;

           iter = pair.begin();
           int lowest = *iter;
           pair.erase(iter);

           iter = pair.end();
           iter--;
           int highest = *iter;
           pair.erase(iter);

           result += (highest - lowest);
        }
        std::cout << result << std::endl;
    }
    return 0;
}
