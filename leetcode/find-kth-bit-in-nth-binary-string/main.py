from typing import List
from collections import defaultdict


class Solution:
    def findKthBit(self, n: int, k: int) -> str:
        last = "0"

        def reverse(s):
            reversed_s = ""
            for i in range(len(s)-1, -1, -1):
                reversed_s += s[i]

            return reversed_s

        def invert(s):
            inverted_s = ""
            for i in range(len(s)):
                if s[i] == "1":
                    inverted_s += "0"
                else:
                    inverted_s += "1"

            return inverted_s

        for _ in range(1, n+1):
            last = last + "1" + reverse(invert(last))

        print(len(last))

        return last[k]


# print(Solution().findKthBit(1, 1))
# print(Solution().findKthBit(2, 1))
# print(Solution().findKthBit(3, 1))
# print(Solution().findKthBit(4, 1))
# print(Solution().findKthBit(5, 1))
# print(Solution().findKthBit(20, 1))
print(Solution().findKthBit(22, 1))
print(Solution().findKthBit(23, 1))
print(Solution().findKthBit(24, 1))
