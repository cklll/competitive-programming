# https://leetcode.com/problems/merge-intervals/

from typing import List

class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort()

        result = [intervals[0]]
        for interval in intervals:
            if result[-1][1] >= interval[0]:
                result[-1][1] = max(result[-1][1], interval[1])
            else:
                result.append(interval)

        return result

print(Solution().merge([[1, 2]]))
print(Solution().merge([[1, 2], [2, 3]]))
print(Solution().merge([[1, 2], [3, 4]]))
print(Solution().merge([[1,4],[2,3]]))
