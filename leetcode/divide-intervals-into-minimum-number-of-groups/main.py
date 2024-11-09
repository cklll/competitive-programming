# https://leetcode.com/problems/divide-intervals-into-minimum-number-of-groups/description/

from typing import List
import heapq

class Solution:
    def minGroups(self, intervals: List[List[int]]) -> int:
        intervals = sorted(intervals)

        group_count = 1
        heap_min_close = [intervals[0][1]]

        for i in range(1,len(intervals)):
            close = heap_min_close[0]

            if intervals[i][0] > close:
                heapq.heappop(heap_min_close)
                heapq.heappush(heap_min_close, intervals[i][1])
            else:
                group_count += 1
                heapq.heappush(heap_min_close, intervals[i][1])

        return group_count




print(Solution().minGroups([[5,10],[6,8],[1,10],[1,5],[2,3]])) # 3
print(Solution().minGroups([[1,3],[5,6],[8,10],[11,13]])) # 1
