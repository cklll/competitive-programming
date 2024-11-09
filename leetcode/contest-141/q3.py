from typing import List

class Solution:
    def maxRemovals(self, source: str, pattern: str, targetIndices: List[int]) -> int:
        dp = [[0 for i in range(len(source)+1)] for j in range(len(targetIndices)+1)]

        for i in range(len(targetIndices)):
            pass






# print(Solution().maxRemovals("abbaa", "aba", [0,1,2])) # 1
# print(Solution().maxRemovals(source = "bcda", pattern = "d", targetIndices = [0,3])) # 2
# print(Solution().maxRemovals(source = "dda", pattern = "dda", targetIndices = [0,1,2])) # 0
print(Solution().maxRemovals(source = "yeyeykyded", pattern = "yeyyd", targetIndices = [0,2,3,4])) # 2
