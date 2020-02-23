// https://codeforces.com/contest/1237/problem/B

#include <iostream>
#include <vector>
// #include <queue>
#include <set>
using namespace std;

// 5
// 3 5 2 1 4
// 4 3 2 5 1

// class QueueElement {
// public:
//   int id;
//   int order;

//     QueueElement(int id, int order) : id(id), order(order) {}

//     bool operator<(const QueueElement &rhs) const
//     {
//         return order < rhs.order;
//     }

//     int x, y;
// };

int main() {
  int n;
  cin >> n;
  vector<int> inNumbers;
  vector<int> outNumbers;

  // priority_queue<QueueElement> permittedOutQueue;
  // set<int> permittedOutNumbers;

  for (int i = 0; i < n; i++) {
    int number;
    cin >> number;
    inNumbers.push_back(number);

    // QueueElement e(number, i);
    // permittedOutQueue.push(e);
  }

  for (int i = 0; i < n; i++) {
    int number;
    cin >> number;
    outNumbers.push_back(number);
  }

  // the nth car does not allow any overtake n-1th car
  // the nth out car

  set<int> outtedNumbers;
  int currentExpectedInIndex = 0;
  int result = 0;
  for (int i = 0; i < n; i++) {
    // permittedOutNumbers.insert(inNumbers[i]);

    outtedNumbers.insert(outNumbers[i]);

    // cout << outNumbers[i] << inNumbers[currentExpectedInIndex] << endl;

    if (outNumbers[i] == inNumbers[currentExpectedInIndex]) {
      currentExpectedInIndex++;
      while (true) {
        if (currentExpectedInIndex == n) {
          break;
        }
        if (outtedNumbers.find(inNumbers[currentExpectedInIndex]) != outtedNumbers.end()) {
          currentExpectedInIndex++;
        } else {
          break;
        }
      }
    } else {
      result++;
    }
    // cout << endl;


    // currentExpectedInIndex

    // found
    // if (permittedOutNumbers.find(outNumbers[i]) != permittedOutNumbers.end()) {
    // }
  }

  cout << result << endl;

  return 0;
}
