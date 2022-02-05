# https://leetcode.com/problems/decode-ways/

class Solution:
    def numDecodings(self, s: str) -> int:

        dp_table = [0 for _ in range(len(s))]

        # base case
        if s[0] == '0':
            dp_table[0] = 0
        else:
            dp_table[0] = 1


        if len(s) > 1:
            if s[1] == '0':
                if int(s[0:2]) > 26:
                    dp_table[1] = 0
                else:
                    dp_table[1] = dp_table[0]
            else:
                if s[0] == '0':
                    dp_table[1] = dp_table[0]
                elif int(s[0:2]) > 26:
                    dp_table[1] = 1
                else:
                    dp_table[1] = dp_table[0] + 1


        for i in range(2, len(s)):
            new_digit = s[i]
            last_digit = s[i-1]
            two_digit = f'{last_digit}{new_digit}'

            if new_digit == '0':
                if last_digit == '0':
                    dp_table[i] = 0
                else:
                    if int(two_digit) > 26:
                        dp_table[i] = 0
                    else:
                        dp_table[i] = dp_table[i-2]
            else:
                if last_digit == '0':
                    dp_table[i] = dp_table[i-1]
                else:
                    if int(two_digit) > 26:
                        dp_table[i] = dp_table[i-1]
                    else:
                        dp_table[i] = dp_table[i-1] + dp_table[i-2]

        # print(dp_table)
        return dp_table[-1]

# print(Solution().numDecodings("27"))
# print(Solution().numDecodings("272"))
# print(Solution().numDecodings("2727"))
# print(Solution().numDecodings("21"))
# print(Solution().numDecodings("210"))
print(Solution().numDecodings("301"))
# print(Solution().numDecodings("2101"))
# print(Solution().numDecodings("0"))
# print(Solution().numDecodings("01"))
# print(Solution().numDecodings("011"))

# print(Solution().numDecodings("1"))
# print(Solution().numDecodings("12"))
# print(Solution().numDecodings("11"))
# print(Solution().numDecodings("10"))
# print(Solution().numDecodings("26"))
# print(Solution().numDecodings("77"))

# print(Solution().numDecodings("101"))
# print(Solution().numDecodings("111"))
# print(Solution().numDecodings("226"))
