# https://leetcode.com/problems/insert-interval/

from typing import List

class Solution:
    # not overlap
    # |----|        |----|
    #        |----|

    # newInterval start before interval start
    # |---|      |------| |------|
    #        |------|
    #

    # newInterval start before interval end
    # |--------||--------|
    #      |-------|

    # overlap multiple
    # |-----||--------|
    # |---------------|
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        if len(intervals) == 0:
            return [newInterval]

        result = []
        current_merge = []

        for interval in intervals:
            if len(current_merge) == 2:
                result.append(interval)
                continue

            # check if can start
            if len(current_merge) == 0:
                if interval[1] < newInterval[0]:
                    result.append(interval)
                    continue

                if newInterval[0] >= interval[0] and newInterval[0] <= interval[1]:
                    current_merge.append(min(interval[0], newInterval[0]))
                elif newInterval[0] <= interval[0]:
                    # if newInterval is the first item
                    if newInterval[1] <= interval[1]:
                        current_merge.append(newInterval[0])
                    elif newInterval[1] >= interval[0]:
                        current_merge.append(newInterval[0])

            # check if can close
            if len(current_merge) == 1:
                if newInterval[1] < interval[0]:
                    current_merge.append(newInterval[1])
                    result.append(current_merge)
                    result.append(interval)
                elif interval[1] > newInterval[1]:
                    current_merge.append(interval[1])
                    result.append(current_merge)

        # make sure to close the last
        if len(current_merge) == 0:
            result.append(newInterval)
        elif len(current_merge) == 1:
            current_merge.append(max(newInterval[1], intervals[-1][1]))
            result.append(current_merge)

        return result

print(Solution().insert([[1,5]], [6, 8]))
# print(Solution().insert([[1,3],[6,9]], [2,5]))
# print(Solution().insert([[1,3],[6,9]], [1,5]))
# print(Solution().insert([[1,3],[6,9]], [1,3]))
# print(Solution().insert([[1,3],[6,9]], [1,7]))
# print(Solution().insert([[1,3],[6,9], [11,12]], [1,10]))
# print(Solution().insert([[2,3],[6,9], [11,12]], [1,8]))
# print(Solution().insert([[4,5]], [2,3]))
# print(Solution().insert([], [2,5]))
