# https://leetcode.com/problems/non-overlapping-intervals/submissions/

from typing import List

class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        # sort intervals by start and length
        intervals.sort(key=lambda x: (x[0], -(x[1]-x[0])))

        # Strategy
        # for each 2 intervals
        # if they are overlapped
        # remove the bigger end one

        removed_count = 0
        i = 0
        j = 1
        while j < len(intervals):
            interval1 = intervals[i]
            interval2 = intervals[j]
            if interval1[1] <= interval2[0]:
                i = j
                j = i+1
                continue
            if interval1[1] >= interval2[1]:
                i = j
                j = i+1
            else:
                j += 1
            removed_count += 1

        return removed_count

print(Solution().eraseOverlapIntervals([[1,100],[11,22],[1,11],[2,12]]))
