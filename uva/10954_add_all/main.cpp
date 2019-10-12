#include <iostream>
#include <queue>
#include <vector>

int main() {
  int n, number;
  while (true) {
    std::priority_queue<int, std::vector<int>, std::greater<int> > pq;
    std::cin >> n;
    if (n == 0) {
      break;
    }
    for (int i = 0; i < n; i++) {
      std::cin >> number;
      pq.push(number);
    }

    int totalCost = 0;
    int number1, number2;
    while (pq.size() > 1) {
      number1 = pq.top();
      pq.pop();
      number2 = pq.top();
      pq.pop();
      totalCost += (number1 + number2);
      pq.push(number1 + number2);
    }
    std::cout << totalCost << std::endl;
  }
  return 0;
}
