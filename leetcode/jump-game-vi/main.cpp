#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int>& nums, int k) {
  int result = nums.at(0);
  int current = 0;
  int minIndex = 1;

  while (current < nums.size() - 1) {
    for (int i = 1; i <= k; i++) {
      int next = current + i;

      if (next == nums.size() - 1) {
        result += nums.at(next);
        return result;
      }

      if (nums.at(next) >= 0) {
        current = next;
        result += nums.at(current);
        minIndex = current + 1;
        break;
      }

      if (nums.at(next) <= nums.at(minIndex)) {
        minIndex = next;
      }

      if (i == k) {
        next = current + minIndex;
        result += nums.at(next);
        current = next;
        minIndex = current + 1;
      }
    }
  }

  return result;
}

int main() {
  vector<int> nums;
  nums.push_back(1);
  nums.push_back(-1);
  nums.push_back(-2);
  nums.push_back(4);
  // nums.push_back(-7);
  // nums.push_back(3);

  cout << solve(nums, 2) << endl;
  return 0;
}
