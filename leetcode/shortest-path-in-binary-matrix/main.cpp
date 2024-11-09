// https://leetcode.com/problems/shortest-path-in-binary-matrix/description/

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
  int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    // edge case
    if (grid[0][0] == 1) {
      return -1;
    }

    if (grid.size() == 1) {
      return 1;
    }

    vector<tuple<int,int>> directions = {
      {-1,-1}, {-1, 0}, {-1,1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1},
    };
    set<tuple<int, int>> visited;
    deque<tuple<int, int, int>> nextStates; // x, y, depth
    nextStates.push_back({0, 0, 1});

    while (!nextStates.empty()) {
      tuple<int, int, int> state = nextStates.front();
      nextStates.pop_front();

      for (auto direction : directions) {
        int x = get<0>(state) + get<0>(direction);
        int y = get<1>(state) + get<1>(direction);

        if (x < 0 || y < 0 || x >= grid.size() || y >= grid.size()) {
          continue;
        } else if (visited.find({x, y}) != visited.end()) {
          continue;
        }

        int depth = get<2>(state) + 1;

        if (grid[x][y] == 0) {
          if (x == grid.size() - 1 && y == grid.size() - 1) {
            return depth;
          } else {
            nextStates.push_back({x, y, depth});
            visited.insert({x, y});
          }
        }
      }
    }

    return -1;
  }
};

int main() {
  Solution sol;

  vector<vector<int>> mat1 = {{0,0,0},{1,1,0},{1,1,0}};
  cout << sol.shortestPathBinaryMatrix(mat1) << endl; // 4

  vector<vector<int>> mat2 = {
    {1,0,0},{1,1,0},{1,1,0},
  };
  cout << sol.shortestPathBinaryMatrix(mat2) << endl; // -1

  vector<vector<int>> mat3 = {
    {0, 1, 1}, {1, 1, 1}, {1, 1, 0},
  };
  cout << sol.shortestPathBinaryMatrix(mat3) << endl; // -1


  return 0;
}
