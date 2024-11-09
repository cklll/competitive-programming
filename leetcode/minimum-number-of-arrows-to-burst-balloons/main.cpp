
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
    int findMinArrowShots(vector<vector<int>>& points) {
      sort(points.begin(),
        points.end(),
        [] (const vector<int> &a, const vector<int> &b)
        {
          if (a[0] == b[0]) {
            return a[1] < b[1];
          }

          return a[0] < b[0];
        }
      );

      int currentStart = points[0][0];
      int currentEnd = points[0][1];
      int result = 0;

      for (int i = 0; i < points.size(); i++) {

        bool isWithin = false;
        // if start point is with range
        // close it out
        if (points[i][0] >= currentStart && points[i][0] <= currentEnd) {
          currentStart = points[i][0];
          isWithin = true;
        }

        // if end point is with range, close it out
        if (points[i][1] >= currentStart && points[i][1] <= currentEnd) {
          currentEnd = points[i][1];
          // isWithin = true; // don't really need this, it would have handled by previous case
        }

        if (isWithin) {
          continue;
        }

        result++; // shoot an arrow to pop previous balloons
        currentStart = points[i][0];
        currentEnd = points[i][1];
      }

      result++; // pop the final balloons

      return result;
    }
};



int main() {
  Solution sol;

  vector<vector<int>> points1 = {
    {5, 9},
    {5, 7},
    {6, 8},
    {9, 10},
    {1, 4},
    {1, 3},
    {7, 11},
    {11, 15},
  };
  cout << sol.findMinArrowShots(points1) << endl;

// Input: points = [[10,16],[2,8],[1,6],[7,12]]
// Output: 2
// Explanation: The balloons can be burst by 2 arrows:
// - Shoot an arrow at x = 6, bursting the balloons [2,8] and [1,6].
// - Shoot an arrow at x = 11, bursting the balloons [10,16] and [7,12].
  vector<vector<int>> points2 = {
    {10,16},{2,8},{1,6},{7,12},
  };
  cout << sol.findMinArrowShots(points2) << endl;


// Input: points = [[1,2],[3,4],[5,6],[7,8]]
// Output: 4
// Explanation: One arrow needs to be shot for each balloon for a total of 4 arrows.
  vector<vector<int>> points3 = {
    {1,2},{3,4},{5,6},{7,8},
  };
  cout << sol.findMinArrowShots(points3) << endl;


// Input: points = [[1,2],[2,3],[3,4],[4,5]]
// Output: 2
// Explanation: The balloons can be burst by 2 arrows:
// - Shoot an arrow at x = 2, bursting the balloons [1,2] and [2,3].
// - Shoot an arrow at x = 4, bursting the balloons [3,4] and [4,5].
  vector<vector<int>> points4 = {
    {1,2},{2,3},{3,4},{4,5},
  };
  cout << sol.findMinArrowShots(points4) << endl;

  return 0;
}
