// https://leetcode.com/problems/sum-root-to-leaf-numbers/?envType=study-plan-v2&envId=top-interview-150
#include<iostream>
#include<string>
using namespace std;

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
    int sumNumbers(TreeNode* root) {
      return dfs(root, "");
    }
private:
  int dfs(TreeNode* root, string current) {
    string num = to_string(root->val);
    string next = current+num;

    if (root->left == nullptr && root->right == nullptr) {
      return stoi(next);
    } else {
      int result = 0;
      if (root->left != nullptr) {
        result += dfs(root->left, next);
      }
      if (root->right != nullptr) {
        result += dfs(root->right, next);
      }
      return result;
    }
  }
};

int main() {
  TreeNode* r = new TreeNode(1);
  r->left = new TreeNode(2);
  r->right = new TreeNode(3);

  cout << (new Solution())->sumNumbers(r) << endl;;
  return 0;
}
