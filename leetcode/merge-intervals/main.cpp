// https://leetcode.com/problems/merge-intervals/description/

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
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
      sort(intervals.begin(), intervals.end());

      int currentStart = intervals[0][0];
      int currentEnd = intervals[0][1];

      vector<vector<int>> result;
      for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i][0] >= currentStart && intervals[i][0] <= currentEnd) {
          if (intervals[i][1] > currentEnd) {
            currentEnd = intervals[i][1];
          }
        } else {
          result.push_back({currentStart, currentEnd});

          currentStart = intervals[i][0];
          currentEnd = intervals[i][1];
        }
      }

      result.push_back({currentStart, currentEnd});

      return result;
    }
};

// Example 1:

// Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]
// Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].

// Example 2:

// Input: intervals = [[1,4],[4,5]]
// Output: [[1,5]]
// Explanation: Intervals [1,4] and [4,5] are considered overlapping.

void printIntervals(vector<vector<int>> intervals) {
  for (auto &subInterval : intervals) {
    for (auto n : subInterval) {
      cout << n << " ";
    }
    cout << " | ";
  }
  cout << endl;
}

int main() {
  vector<vector<int>> intervals1 = {{1,3},{2,6},{8,10},{15,18}};
  vector<vector<int>> intervals2 = {{1,4},{4,5}};

  Solution sol;

  printIntervals(sol.merge(intervals1));
  printIntervals(sol.merge(intervals2));

  return 0;
}
