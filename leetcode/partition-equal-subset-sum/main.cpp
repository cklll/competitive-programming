// https://leetcode.com/problems/partition-equal-subset-sum/description/

#include<iostream>
#include<string>
#include<vector>
#include<utility>
using namespace std;

class Solution {
public:
  bool canPartition(vector<int>& nums) {
    int sum = 0;
    for (auto &num : nums) {
      sum += num;
    }

    if (sum % 2 == 1) {
      return false;
    }

    int target = sum / 2;

    bool dp[nums.size() + 1][target + 1];

    dp[0][0] = true;
    for (int i = 1; i <= nums.size(); i++) {
      dp[i][0] = true;
    }

    for (int i = 1; i <= target; i++) {
      dp[0][i] = false;
    }

    for (int i = 1; i <= target; i++) {
      for (int j = 0; j < nums.size(); j++) {
        dp[j+1][i] = dp[j][i];

        if (nums[j] > i) {
          continue;
        }

        dp[j+1][i] = dp[j][i] || dp[j][i-nums[j]];
      }
    }

    return dp[nums.size()][target];
  }
};

int main() {
  // vector<int> nums({1,5,11,5});
  // // vector<int> nums({1,2,3,5});

  // Solution sol;
  // cout << sol.canPartition(nums) << endl;


  string s = "AbCG";

  for (char &c : s) {
    if (c >= 'A' && c <= 'Z') {
      c -= ('Z' - 'z');
    }
  }

  cout << s  << endl;

}
