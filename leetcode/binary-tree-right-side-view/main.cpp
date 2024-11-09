
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
    vector<int> result;

    vector<int> rightSideView(TreeNode* root) {
      if (!root) {
        return {};
      }

      dfs(root, 1);

      return result;
    }

    private:
      void dfs(TreeNode* current, int level) {
        if (level > result.size()) {
          result.push_back(current->val);
        } else {
          result[level-1] = current->val;
        }

        if (current->left) {
          dfs(current->left, level+1);
        }
        if (current->right) {
          dfs(current->right, level+1);
        }
      }
};

int main() {
  Solution sol;

  TreeNode child = TreeNode(3, nullptr, nullptr);
  TreeNode head = TreeNode(1, nullptr, &child);

  vector<int> result = sol.rightSideView(&head);
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

  return 0;
}
