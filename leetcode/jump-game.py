# https://leetcode.com/problems/jump-game/

from typing import List

class Solution:
    def canJump(self, nums: List[int]) -> bool:
        if len(nums) == 1:
            return True

        indices_of_zero = []
        for i in range(len(nums)):
            if nums[i] == 0:
                indices_of_zero.append(i)

        for i in range(len(indices_of_zero)):
            zero_index = indices_of_zero[i]
            passed = False
            for j in range(zero_index, -1, -1):
                max_step = nums[j]
                largest_index = j + max_step
                if largest_index >= len(nums) - 1:
                    return True

                if largest_index > zero_index:
                    passed = True
                    break

            if not passed:
                return False

        return True


# print(Solution().canJump([2,3,1,1,4]))
# print(Solution().canJump([3,2,1,0,4]))
# print(Solution().canJump([2,0,0]))
print(Solution().canJump([3,0,8,2,0,0,1]))
# print(Solution().canJump([3,2,1,0,4]))
