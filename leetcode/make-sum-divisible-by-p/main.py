# https://leetcode.com/problems/make-sum-divisible-by-p/description/?envType=daily-question&envId=2024-10-03

from typing import List
from collections import defaultdict

class Solution:
    def minSubarray(self, nums: List[int], p: int) -> int:
        array_sum = sum(nums)
        if array_sum % p == 0:
            return 0

        for num_removal in range(1, len(nums)):
            subarray_sum = array_sum - sum(nums[:num_removal])

            if subarray_sum % p == 0:
                return num_removal

            for idx in range(num_removal, len(nums)):
                subarray_sum = subarray_sum - nums[idx] + nums[idx - num_removal]
                if subarray_sum % p == 0:
                    return num_removal

        return -1





print(Solution().minSubarray([3,1,4,2], 6)) # 1
print(Solution().minSubarray([6,3,5,2], 9)) # 2
print(Solution().minSubarray([1,2,3], 3)) # 0


print(Solution().minSubarray([1,2,3], 9)) # -1

print(Solution().minSubarray([2,1,4,3], 6)) # 1
