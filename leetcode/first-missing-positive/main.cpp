// https://leetcode.com/problems/first-missing-positive/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
      // use vector index as hash table
      // for each integer
      //   get the value, and swap it with that index
      //   until index == number - 1 (0 index, i.e. "1" maps to nums.at(0))

      // 2, 5, 3, 1, 4
      // i = 0
      // -> 5, 2, 3, 1, 4
      // -> 4, 2, 3, 1, 5
      // -> 1, 2, 3, 4, 5

      for (int i = 0; i < nums.size(); i++) {
        int num;

        while (nums.at(i) != i+1) {
          int num = nums.at(i);

          if (num < 1 || num > nums.size()) {
            break;
          }
          int tmp = nums.at(num-1);

          // edge case: if the swap value is the same, break
          if (tmp == num) {
            break;
          }

          nums.at(i) = tmp;
          nums.at(num-1) = num;
        }
      }

      for (int i = 0; i < nums.size(); i++) {
        if (nums.at(i) != i + 1) {
          return i + 1;
        }
      }

      // that means the array is all 1, 2, 3, ..... N
      return nums.size() + 1;
    }
};

int main() {
  // vector<int> nums = {1, 2, 0};
  // vector<int> nums = {-1, -2, 0};
  // vector<int> nums = {1, 2};
  // vector<int> nums = {1, 3};
  // vector<int> nums = {1, 1};
  vector<int> nums = {1, 1, 1, 1};
  // vector<int> nums = {3, 3, 5};
  cout << (new Solution())->firstMissingPositive(nums) << endl;
  return 0;
}
