# https://leetcode.com/problems/minimum-array-end/description/

from typing import List
from collections import defaultdict

class Solution:
    def minEnd(self, n: int, x: int) -> int:
        bin_n_1 = bin(n-1)[2:]

        bin_x = ['0' for _ in range(64)]
        bin_x_reversed = ''.join(reversed(bin(x)[2:]))
        for i in range(len(bin_x_reversed)):
            bin_x[64-i-1] = bin_x_reversed[i]

        index_n_1 = len(bin_n_1) - 1
        index_x = 63

        while index_n_1 >= 0:
            if bin_x[index_x] == '0':
                bin_x[index_x] = bin_n_1[index_n_1]
                index_x -= 1
                index_n_1 -= 1
            else:
                index_x -= 1

        return int(''.join(bin_x), 2)

print(Solution().minEnd(n = 3, x = 4)) # 6
print(Solution().minEnd(n = 2, x = 7)) # 15
print(Solution().minEnd(n = 8, x = 7)) # 63
print(Solution().minEnd(n = 36845498, x = 15573081)) #
