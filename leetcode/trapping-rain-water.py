# https://leetcode.com/problems/trapping-rain-water/

from typing import List

class Solution:
    def trap(self, heights: List[int]) -> int:
        # given a index, the max height in previous visited index
        max_heights_from_left = []
        max_heights_from_right = [0] * len(heights)
        current_max_from_left = 0
        current_max_from_right = 0

        for i in range(len(heights)):
            current_max_from_left = max(current_max_from_left, heights[i])
            max_heights_from_left.append(current_max_from_left)

            right_index = len(heights)-i-1
            current_max_from_right = max(current_max_from_right, heights[right_index])
            max_heights_from_right[right_index] = current_max_from_right

        # print(max_heights_from_left)
        # print(max_heights_from_right)
        result = 0
        # trapped_waters = []
        for i in range(len(heights)):
            # trapped_water = max(min(max_heights_from_left[i], max_heights_from_right[i]) - heights[i], 0)
            # trapped_waters.append(trapped_water)
            result += max(min(max_heights_from_left[i], max_heights_from_right[i]) - heights[i], 0)

        return result


import unittest
tc = unittest.TestCase()
tc.assertEqual(Solution().trap([0,1,0,2,1,0,1,3,2,1,2,1]), 6)
tc.assertEqual(Solution().trap([4,2,0,3,2,5]), 9)
