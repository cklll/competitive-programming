# https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/description/

class Solution:
    def minSwaps(self, s: str) -> int:
        if s == "":
            return 0

        open_count = 0
        result = 0

        chars = list(s)
        right_index = len(chars) - 1

        for i in range(len(chars)):
            c = chars[i]

            if c == "[":
                # good
                open_count += 1
                continue
            if c == "]":
                if open_count > 0:
                    open_count -= 1
                else:
                    result += 1
                    open_count += 1
                    chars[i] = "["

                    while chars[right_index] != "[":
                        right_index -= 1

                    chars[right_index] = "]"

        return result







print(Solution().minSwaps("][][")) # 1
print(Solution().minSwaps("]]][[[")) # 2
print(Solution().minSwaps("[]")) # 0

print(Solution().minSwaps("[[][[]]]")) # 0

print(Solution().minSwaps("][][[]")) # 1 # ][][[] -> [[][]]

print(Solution().minSwaps("[][[[][[[]]]]][]")) # 0
