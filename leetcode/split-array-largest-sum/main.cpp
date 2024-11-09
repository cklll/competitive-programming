// https://leetcode.com/problems/split-array-largest-sum/description/


#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<unordered_set>
#include<map>
#include<algorithm>
#include<unordered_map>
#include<deque>
#include<queue>
#include<utility>
#include<cmath>
using namespace std;

class Solution {
public:
  int splitArray(vector<int>& nums, int k) {
    int left = 0;
    int right = 0;

    for (auto num : nums) {
      right += num;

      if (num > left) {
        left = num;
      }
    }

    int lastDoable = right;

    while (true) {
      int mid = (left + right) / 2;

      // cout << left << " " << right << " " << mid  <<  endl;

      if (left == right) {
        break;
      }

      // for the last case, right-left = 1
      // if (right - left == 1 && lastDoable > left) {
      //   left++;
      //   continue;
      // }

      if (doable(nums, k, mid)) {
        // cout << "doable " << mid << endl;
        right = mid;
        lastDoable = mid;
      } else {
        // cout << "not doable " << mid << endl;
        left = mid+1;
      }
    }


    return lastDoable;
  }

  bool doable(vector<int>& nums, int k, int max) {
    int current = 0;
    for (int i = 0; i < nums.size(); i++) {
      // cout << k  << " " << current << endl;
      if (current + nums[i] <= max) {
        current += nums[i];
        continue;
      }

      k--;
      if (k == 0) {
        return false;
      }
      current = nums[i];
    }

    return true;
  }

};


int main() {
// Input: nums = [7,2,5,10,8], k = 2
// Output: 18

// Input: nums = [1,2,3,4,5], k = 2
// Output: 9

  Solution sol;

  vector<int> nums = {1,2,3,4,5};
  cout << sol.splitArray(nums, 2) << endl;

  // vector<int> nums = {7,2,5,10,8};
  // cout << sol.splitArray(nums, 2) << endl;

  // vector<int> nums = {1,4,4};
  // cout << sol.splitArray(nums, 3) << endl;
  return 0;
}
