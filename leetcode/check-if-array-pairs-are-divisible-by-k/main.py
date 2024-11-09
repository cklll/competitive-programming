# https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/description/?envType=daily-question&envId=2024-10-01

from typing import List
from collections import defaultdict

class Solution:
    def canArrange(self, arr: List[int], k: int) -> bool:
        remainders_count = defaultdict(int)

        for num in arr:
            remainders_count[num % k] += 1


        for remainder, _ in remainders_count.items():
            other = k - remainder
            if remainder == 0:
                other = 0

            while remainders_count[remainder] > 0:
                remainders_count[remainder] -= 1

                if remainders_count[other] >= 1:
                    remainders_count[other] -= 1
                else:
                    return False

        return True



print(Solution().canArrange([1,2,3,4,5,10,6,7,8,9], 5)) # true
print(Solution().canArrange([1,2,3,4,5,6], 7)) # true
print(Solution().canArrange([1,2,3,4,5,6], 10)) # false
print(Solution().canArrange([5,5,1,2,3,4], 10)) # false
