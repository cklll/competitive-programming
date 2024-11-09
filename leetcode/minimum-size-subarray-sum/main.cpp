
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
    int minSubArrayLen(int target, vector<int>& nums) {
      int leftIndex = 0;
      int current = nums.at(0);
      int min = nums.size();

      if (current >= target) {
        return 1;
      }

      for (int i = 1; i < nums.size(); i++) {
        current += nums.at(i);

        while (current - nums.at(leftIndex) >= target) {
          current -= nums.at(leftIndex);
          leftIndex++;
        }

        if (current >= target) {
          int currentLength = i - leftIndex + 1;
          if (currentLength < min) {
            min = currentLength;
          }
        }
      }

      if (current < target) {
        return 0;
      }
      return min;
    }
};

int main() {
  Solution sol;

// Example 1:

// Input: target = 7, nums = [2,3,1,2,4,3]
// Output: 2
// Explanation: The subarray [4,3] has the minimal length under the problem constraint.

// Example 2:

// Input: target = 4, nums = [1,4,4]
// Output: 1

// Example 3:

// Input: target = 11, nums = [1,1,1,1,1,1,1,1]
// Output: 0


  vector<int> nums1 = {2,3,1,2,4,3};
  cout << sol.minSubArrayLen(7, nums1) << endl;

  vector<int> nums2 = {1,4,4};
  cout << sol.minSubArrayLen(4, nums2) << endl;

  vector<int> nums3 = {1,1,1,1,1,1,1,1};
  cout << sol.minSubArrayLen(11, nums3) << endl;

  vector<int> nums4 = {10,2,3};
  cout << sol.minSubArrayLen(6, nums4) << endl;
  return 0;
}
