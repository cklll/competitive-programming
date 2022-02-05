# https://leetcode.com/problems/kth-smallest-element-in-a-bst/

from typing import Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        num_nodes = self.count_nodes(root.left)

        if num_nodes >= k:
            return self.kthSmallest(root.left, k)
        elif num_nodes == k - 1:
            return root.val
        else:
            return self.kthSmallest(root.right, k - num_nodes - 1)




    # (int, int), 1st value is the result, 2nd value return how many nodes are in the left trees
    def count_nodes(self, root):
        if not root:
            return 0

        return 1 + self.count_nodes(root.left) + self.count_nodes(root.right)

print(
    Solution().kthSmallest(
        TreeNode(1), 1,
    )
)
# print(
#     Solution().kthSmallest(
#         TreeNode(2, TreeNode(1)), 2,
#     )
# )
# print(
#     Solution().kthSmallest(
#     TreeNode(2, TreeNode(1), TreeNode(3)), 3,
#     )
# )

# print(
#     Solution().kthSmallest(
#     TreeNode(3, TreeNode(1, None, TreeNode(2)), TreeNode(4)), 4,
#     )
# )
print(
    Solution().kthSmallest(
    TreeNode(5, TreeNode(3, TreeNode(2, TreeNode(1)), TreeNode(4)), TreeNode(6)), 6,
    )
)
