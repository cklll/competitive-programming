# https://leetcode.com/problems/find-subtree-sizes-after-changes/

from typing import List
from collections import defaultdict

class Solution:
    def findSubtreeSizes(self, parent: List[int], s: str) -> List[int]:
        ancestors = defaultdict(dict)

        def compute_ancestors(index):
            if parent[index] == -1:
                return {}

            if len(ancestors[index]) > 0:
                return ancestors[index]

            ancestors[index] = {
                **compute_ancestors(parent[index])
            }
            ancestors[index][s[parent[index]]] = parent[index]


            return ancestors[index]

        for i in range(len(s)):
            compute_ancestors(i)

        # print(ancestors)


        new_parents = [p for p in parent]
        for i in range(len(parent)):
            if s[i] in ancestors[i]:
                new_parents[i] = ancestors[i][s[i]]

        # print(new_parents)

        children = defaultdict(list)

        for i in range(len(new_parents)):
            children[new_parents[i]].append(i)

        root = children[-1][0]

        result = [0 for _ in range(len(new_parents))]
        def recursive(current_index: int):
            result[current_index] += 1

            for child in children[current_index]:
                result[current_index] += recursive(child)

            return result[current_index]

        recursive(root)

        return result


# print(Solution().findSubtreeSizes(parent = [-1,0,0,2,3], s = "aabab"))
print(Solution().findSubtreeSizes(parent = [-1,0,0,1,1,1], s = "abaabc"))
print(Solution().findSubtreeSizes(parent = [-1,0,4,0,1], s = "abbba"))
