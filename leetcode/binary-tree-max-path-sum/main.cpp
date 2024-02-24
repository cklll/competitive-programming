// https://leetcode.com/problems/binary-tree-maximum-path-sum/description/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
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
int max;

public:

    int maxPathSum(TreeNode* root) {
      this->max = root->val;
      this->recursive(root);
      return this->max;
    }

    int recursive(TreeNode* root) {
      int leftGain = 0;
      int rightGain = 0;
      if (root->left != nullptr) {
        leftGain = recursive(root->left);
        if (leftGain < 0) { leftGain = 0; }
      }
      if (root->right != nullptr) {
        rightGain = recursive(root->right);
        if (rightGain < 0) { rightGain = 0; }
      }

      int max = leftGain + root->val + rightGain;
      // if this node is used as "root", then can use both children
      if (max > this->max) {
        this->max = max;
      }
      // else can only take one of the child
      if (leftGain+root->val > rightGain+root->val) {
        return leftGain+root->val;
      }
      return rightGain+root->val;
    }
};

int main() {
  Solution sol;
  TreeNode* r = new TreeNode(1);
  r->left = new TreeNode(2);
  r->right = new TreeNode(3);

  cout << sol.maxPathSum(r) << endl;;
  return 0;
}
