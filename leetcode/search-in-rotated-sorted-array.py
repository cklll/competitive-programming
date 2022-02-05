# https://leetcode.com/problems/search-in-rotated-sorted-array/submissions/

# Runtime: 44 ms, faster than 49.40% of Python3 online submissions for Search in Rotated Sorted Array.
# Memory Usage: 14.4 MB, less than 93.86% of Python3 online submissions for Search in Rotated Sorted Array.

class Solution:
    def search(self, nums: List[int], target: int) -> int:
        return self.solve(nums, target, 0, len(nums) - 1)

    def solve(self, nums, target, left, right):
        if right - left <= 1:
            if nums[left] == target:
                return left
            if nums[right] == target:
                return right
            return -1

        middle = (left + right) // 2
        if nums[middle] == target:
            return middle

        left_first_index = left
        left_last_index = middle - 1
        right_first_index = middle + 1
        right_last_index = right

        # sorted
        if target > nums[left_first_index] and target < nums[left_last_index]:
            # must be in this group or doesn't exist in both group
            return self.solve(nums, target, left_first_index, left_last_index)
        elif target > nums[right_first_index] and target < nums[right_last_index]:
            return self.solve(nums, target, right_first_index, right_last_index)
        else:
            left_result = self.solve(nums, target, left_first_index, left_last_index)
            if left_result != -1:
                return left_result
            return self.solve(nums, target, right_first_index, right_last_index)
