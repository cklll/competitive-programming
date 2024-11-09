# https://leetcode.com/problems/rank-transform-of-an-array/?envType=daily-question&envId=2024-10-02

from typing import List
from collections import defaultdict

class Solution:
    def arrayRankTransform(self, arr: List[int]) -> List[int]:
        sorted_arr = sorted(arr)
        d = {}
        counter = 1
        for num in sorted_arr:
            if num in d:
                continue
            d[num] = counter
            counter += 1

        result = []

        for num in arr:
            result.append(d[num])

        return result

print(Solution().arrayRankTransform([40,10,20,30])) # [4,1,2,3]
print(Solution().arrayRankTransform([100,100,100])) # [1,1,1]
print(Solution().arrayRankTransform([37,12,28,9,100,56,80,5,12])) # [5,3,4,2,8,6,7,1,3]
