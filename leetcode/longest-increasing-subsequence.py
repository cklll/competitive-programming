# https://leetcode.com/problems/longest-increasing-subsequence/submissions/

from typing import List

class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        # DP
        table = [1]

        # for each num, iterate the table, and find the next best  sub-sequence
        for i in range(1, len(nums)):
            num = nums[i]

            new_seq_len = 1
            for j in range(len(table)):
                prev_num = nums[j]
                if num > prev_num:
                    if table[j] + 1 > new_seq_len:
                        new_seq_len = table[j] + 1


            table.append(new_seq_len)

        return max(table)


print(Solution().lengthOfLIS([1,3,6,7,9,4,10,5,6]))
