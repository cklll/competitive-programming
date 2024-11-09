// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<tuple<int, int, int>> nodes; // col, row, val
    int leftMost = 0;
    int rightMost = 0;

    vector<vector<int>> verticalTraversal(TreeNode* root) {
      dfs(root, 0, 0);

      unordered_map<int, vector<pair<int, int>>> colWithHeightAndVal; // col -> [<height, val>]
      for (auto node : nodes) {
        colWithHeightAndVal[get<0>(node)].push_back(make_pair(get<1>(node), get<2>(node)));
      }

      vector<vector<int>> result;
      for (int i = leftMost; i <= rightMost; i++) {
        result.push_back({});
      }

      for (auto it : colWithHeightAndVal) {
        int col = it.first;
        sort(it.second.begin(), it.second.end());

        vector<int> nums;
        for (auto p : it.second) {
          nums.push_back(p.second);
        }

        result[col-leftMost] = nums;
      }

      return result;
    }

    void dfs(TreeNode* current, int col, int row) {
      nodes.push_back(make_tuple(col, row, current->val));

      if (col < leftMost) {
        leftMost = col;
      } else if (col > rightMost) {
        rightMost = col;
      }

      if (current->left) {
        dfs(current->left, col-1, row+1);
      }
      if (current->right) {
        dfs(current->right, col+1, row+1);
      }

    }
};

void printAns(vector<vector<int>> ans) {
  for (auto sub : ans) {
    for (auto num : sub) {
      cout << num << " ";
    }
    cout << " | ";
  }
  cout << endl;
}

int main() {
  Solution sol;
  TreeNode node4 = TreeNode(4);
  TreeNode node5 = TreeNode(6);
  TreeNode node2 = TreeNode(2, &node4, &node5);

  TreeNode node6 = TreeNode(5);
  TreeNode node7 = TreeNode(7);
  TreeNode node3 = TreeNode(3, &node6, &node7);

  TreeNode node1 = TreeNode(8, &node2, &node3);

  printAns(sol.verticalTraversal(&node1));
  return 0;
}
