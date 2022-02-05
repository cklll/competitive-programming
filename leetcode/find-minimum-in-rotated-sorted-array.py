# https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

from typing import List

class Solution:
    def findMin(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]
        if nums[0] < nums[-1]:
            return nums[0]

        mid = len(nums) // 2
        nums1 = nums[:mid]
        nums2 = nums[mid:]

        if nums1[0] > nums1[-1]:
            return self.findMin(nums1)
        else:
            return self.findMin(nums2)

print(Solution().findMin([3,4,5,1,2]))
print(Solution().findMin([4,5,6,7,0,1,2]))
print(Solution().findMin([11,13,15,17]))
