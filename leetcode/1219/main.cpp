// https://leetcode.com/contest/weekly-contest-157/problems/path-with-maximum-gold/

#include <iostream>
#include <vector>
#include <set>
#include <utility>
using namespace std;

int directions[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

int dfs(vector<vector<int> >& grid, int row, int column) {
  // don't visit
  if (grid[row][column] == 0) {
    return 0;
  }

  // mark as visited, reset the number at the end
  int goldNum = grid[row][column];
  grid[row][column] = 0;

  int result = 0;
  for (int i = 0; i < 4; i++) {
    int newRow = row + directions[i][0];
    int newColumn = column + directions[i][1];

    if (newRow >= 0 && newColumn >= 0 && newRow < grid.size() && newColumn < grid[0].size()) {
      result = max(result, dfs(grid, newRow, newColumn));
    }
  }

  grid[row][column] = goldNum;

  return result + goldNum;
}

int main() {
  // 9
  vector<vector<int> > grid {
    { 1, 2, 3 },
    { 0, 4, 0 },
  };

  // 28
  // vector<vector<int> > grid {
  //   { 1, 0, 7 },
  //   { 2, 0, 6 },
  //   { 3, 4, 5 },
  //   { 0, 3, 0 },
  //   { 9, 0, 20 },
  // };

  // 24
  // vector<vector<int> > grid {
  //   { 0, 6, 0 },
  //   { 5, 8, 7 },
  //   { 0, 9, 0 },
  // };

  int result = 0;
  for (int row = 0; row < grid.size(); row++) {
    for (int column = 0; column < grid[0].size(); column++) {
      result = max(result, dfs(grid, row, column));
    }
  }

  cout << result << endl;

  return 0;
}
