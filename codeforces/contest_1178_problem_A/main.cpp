// https://codeforces.com/contest/1178/problem/A

#include <iostream>
#include <vector>
using namespace std;


int main() {
  int n;
  cin >> n;

  vector<int> nums;
  int total = 0;
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    total += num;
    nums.push_back(num);
  }

  int current = nums[0];
  vector<int> parties;
  parties.push_back(1);

  for (int i = 1; i < n; i++) {
    if (nums[0] >= nums[i] * 2) {
      current += nums[i];
      parties.push_back(i + 1);
    }
    if (current * 2 > total) {
      cout << parties.size() << endl;
      for (auto it = parties.begin(); it != parties.end(); it++) {
        cout << *it << " ";
      }
      cout << endl;
      return 0;
    }
  }

  cout << 0 << endl;

  return 0;
}
