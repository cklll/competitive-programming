# https://leetcode.com/problems/longest-consecutive-sequence/submissions/

class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        s = set()

        for num in nums:
            s.add(num)

        # then for each num, it iterate both directions.
        # record the visited num to prevent visiting the chain twice

        visited = set()
        max_counter = 0
        for num in nums:
            if num in visited:
                continue

            current_counter = 1

            # iterate left
            current_num = num - 1
            while current_num in s:
                visited.add(current_num)
                current_counter += 1
                current_num -= 1

            # iterate right
            current_num = num + 1
            while current_num in s:
                visited.add(current_num)
                current_counter += 1
                current_num += 1

            max_counter = max(max_counter, current_counter)

        return max_counter
