// https://codeforces.com/problemset/problem/1651/C

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// we could sort nums and do binary search.
// Could be slightly faster but we are only calling this function a few times so it should be fine
unsigned long closestDiff(int a, vector<int> nums) {
  unsigned long result = abs(a - nums.at(0));

  for (auto num : nums) {
    if (abs(a - num) < result) {
      result = abs(a - num);
    }
  }

  return result;
}

int main() {
  int t, n;
  cin >> t;

  while (t--) {
    cin >> n;
    vector<int> row1;
    vector<int> row2;

    int num;
    for (int i = 0; i < n; i++) {
      cin >> num;
      row1.push_back(num);
    }
    for (int i = 0; i < n; i++) {
      cin >> num;
      row2.push_back(num);
    }

    if (n == 1) {
      cout << abs(row1.at(0) - row2.at(0)) << endl;
      continue;
    }

    // basically, we only need to make sure the 4 corner nodes are connected to the other side
    // it will requires 2 - 4 only edges

    // case 1, row1[0] to row2[0]
    //   then row1[-1] to row2[-1]
    //   or (row1[-1] to row2[any]) + (row2[-1] to row1[any])

    // case 2, row1[0] to row2[-1]
    //   then row1[-1] to row2[0]
    //   or (row1[-1] to row2[any]) + (row2[0] to row1[any])

    // case 3, row1[0] to row2[any]
    //   and  row1[-1] to row2[any]
    //   and  row2[0] to row1[any]
    //   and  row2[-1] to row1[any]

    // case 4, row1[0] to row2[any]
    //  and row2[0] to row1[any]
    //  and row1[-1] to row2[-1]

    // case 5, row1[-1] to row2[0]
    //  and row1[0] to row2[any]
    //  and row2[-1] to row1[any]

    // where [any] means finding the cheaper cost.

    // case 1
    unsigned long case1 = abs(row1.at(0) - row2.at(0));
    long case11 = abs(row1.back() - row2.back());
    long case12 = closestDiff(row1.back(), row2) + closestDiff(row2.back(), row1);

    case1 += min(case11, case12);

    // case 2
    unsigned long case2 = abs(row1.at(0) - row2.back());
    long case21 = abs(row1.back() - row2.at(0));
    long case22 = closestDiff(row1.back(), row2) + closestDiff(row2.at(0), row1);
    case2 += min(case21, case22);


    // case 3
    unsigned long case3 = closestDiff(row1.at(0), row2)
      + closestDiff(row1.back(), row2)
      + closestDiff(row2.at(0), row1)
      + closestDiff(row2.back(), row1);


    unsigned long case4 = closestDiff(row1.at(0), row2)
      + closestDiff(row2.at(0), row1)
      + abs(row1.back() - row2.back());

    unsigned long case5 = abs(row1.back() - row2.at(0))
      + closestDiff(row1.at(0), row2)
      + closestDiff(row2.back(), row1);

    unsigned long result = min(case1, case2);
    result = min(result, case3);
    result = min(result, case4);
    result = min(result, case5);

    cout << result << endl;
  }

  return 0;
}
