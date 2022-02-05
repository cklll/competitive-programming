# https://leetcode.com/problems/maximum-product-subarray/submissions/

from typing import List

# very stupid approach
class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        # split to list of list, separated by 0
        # it's easier to handle

        nums_of_nums = []
        current_nums = []
        current_max = nums[0]
        for num in nums:
            if num == 0:
                current_max = 0 # just in case if all other nums are negative
                if current_nums:
                    nums_of_nums.append(current_nums)
                current_nums = []
            else:
                current_nums.append(num)

        if len(current_nums) > 0:
            nums_of_nums.append(current_nums)

        # the result will be either:
        # 1. when number of negative numbers is even, product of all nums
        # 2. when is odd, product until last negative number (excluding),
        #                 OR product from 2nd negative number
        for sub_nums in nums_of_nums:
            # use stupid approach.
            num_of_neg = 0
            first_neg_index = -1
            last_neg_index = -1
            for i in range(len(sub_nums)):
                num = sub_nums[i]
                if num < 0:
                    num_of_neg += 1
                    if first_neg_index == -1:
                        first_neg_index = i
                    last_neg_index = i

            if num_of_neg % 2 == 0:
                sub_max = sub_nums[0]
                for num in sub_nums[1:]:
                    sub_max *= num
            else:
                sub_max1 = sub_nums[0]
                for num in sub_nums[1:last_neg_index]:
                    sub_max1 *= num

                # only the last num is negative
                if first_neg_index+1 == len(sub_nums):
                    sub_max2 = sub_nums[first_neg_index]
                else:
                    sub_max2 = 1
                    for num in sub_nums[first_neg_index+1:]:
                        sub_max2 *= num

                sub_max = max(sub_max1, sub_max2)

            current_max = max(sub_max, current_max)

        return current_max

print(Solution().maxProduct([2,-5,-2,-4,3]))
print(Solution().maxProduct([2,3,-2,4]))
print(Solution().maxProduct([-2,0,-1]))
print(Solution().maxProduct([0]))
print(Solution().maxProduct([0, 2]))
