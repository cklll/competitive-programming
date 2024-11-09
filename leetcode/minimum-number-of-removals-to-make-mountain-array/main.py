# https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/

from typing import List
from collections import defaultdict


class Solution:
    def minimumMountainRemovals(self, nums: List[int]) -> int:
        dp_increasing = [1 for i in range(len(nums))]

        for i in range(1, len(nums)):
            for j in range(i):
                if nums[i] > nums[j]:
                    dp_increasing[i] = max(dp_increasing[i], dp_increasing[j]+1)


        dp_decreasing = [1 for i in range(len(nums))]
        for i in range(len(nums)-1, -1, -1):
            for j in range(len(nums)-1, i, -1):
                if nums[j] < nums[i]:
                    dp_decreasing[i] = max(dp_decreasing[i], dp_decreasing[j]+1)

        result = len(nums)
        for i in range(len(nums)):
            # for j in range(i, len(nums)):
            if dp_decreasing[i] > 1 and dp_increasing[i] > 1:
                left_removal = i - dp_increasing[i] + 1
                right_removal = len(nums) - dp_decreasing[i] - i

                # print(i, left_removal, right_removal)

                result = min(
                    result,
                    left_removal + right_removal
                )

        # print(dp_increasing)
        # print(dp_decreasing)

        return result


print(Solution().minimumMountainRemovals([1,3,1])) # 0
print(Solution().minimumMountainRemovals([2,1,1,5,6,2,3,1])) # 3
print(Solution().minimumMountainRemovals([4,3,2,1,1,2,3,1])) # 4
print(Solution().minimumMountainRemovals([1,2,3,4,4,3,2,1])) # 1
