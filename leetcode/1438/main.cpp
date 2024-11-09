// https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/description/


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
  int longestSubarray(vector<int>& nums, int limit) {
    int result = 0;
    int current = 1;

    return result;
  }
};

int main() {
  Solution sol;

  // vector<int> v = {8,2,4,7}; int limit = 4; // 2
  // vector<int> v = {10,1,2,4,7,2}; int limit = 5; // 4
  // vector<int> v = {4,2,2,2,4,4,2,2}; int limit = 0; // 3
  vector<int> v = {1,5,6,7,8,10,6,5,6}; int limit = 4; // 5

  cout << sol.longestSubarray(v, limit) << endl;
  return 0;
}
