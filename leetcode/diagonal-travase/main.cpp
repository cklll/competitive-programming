// https://leetcode.com/problems/diagonal-traverse/description/

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
  vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
    int currentx = 0;
    int currenty = 0;
    string direction = "UP";

    int lenx = mat[0].size();
    int leny = mat.size();

    vector<int> result;
    result.push_back(mat[0][0]);

    while (result.size() != (lenx * leny)) {
      if (direction == "UP") {
        // try to move to up right
        if (currenty > 0 && currentx < (lenx-1)) {
          currenty--;
          currentx++;
        } else if (currenty == 0 && currentx < (lenx-1)) {
          // if top, try to move right
          currentx++;
          direction = "DOWN";
        } else {
          currenty++;
          direction = "DOWN";
        }
      } else {
        // try to move down left
        if (currenty < (leny-1) && currentx > 0) {
          currenty++;
          currentx--;
        } else if (currenty < (leny-1)) {
          // try to move down
          currenty++;
          direction = "UP";
        } else {
          currentx++;
          direction = "UP";
        }
      }

      result.push_back(mat[currenty][currentx]);
    }

    return result;
  }
};

void print(vector<int> v) {
  for (auto i : v) {
    cout << i << " ";
  }
  cout << endl;
}

int main() {
  Solution sol;

  vector<vector<int>> mat1 = {{1,2},{3,4},{5,6}};
  print(sol.findDiagonalOrder(mat1));  // [1,2,3,5,4,6]

  vector<vector<int>> mat2 = {{1,2,3}};
  print(sol.findDiagonalOrder(mat2));  // [1,2,3]

  vector<vector<int>> mat3 = {{1},{2},{3}};
  print(sol.findDiagonalOrder(mat3));  // [1,2,3]


  vector<vector<int>> mat4 = {{1,2,3},{4,5,6}};
  print(sol.findDiagonalOrder(mat4));  // [1,2,4,5,3,6]
  return 0;
}

// 1
// 2
// 3

// 1 2
// 3 4
// 5 6

// [[1,2],[3,4],[5,6]]
// [1,2,3,5,4,6]

// 1 2 3
// 4 5 6

// [[1,2,3],[4,5,6]]
// [1,2,4,5,3,6]

// 1 2
// 3 4
// 5 6
