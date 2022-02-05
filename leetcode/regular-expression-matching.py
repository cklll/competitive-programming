# https://leetcode.com/problems/regular-expression-matching/

class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        dp_table = [[False for _ in range(len(p)+1)] for _ in range(len(s)+1)]
        dp_table[0][0] = True # both s and p are empty string

        # initialize first row: may not be false because * can match zero
        for i in range(2, len(p)+1):
            if p[i-1] == "*":
                if dp_table[0][i-2]:
                    dp_table[0][i] = True

        for i in range(1, len(s)+1):
            for j in range(1, len(p)+1):
                if p[j-1] == "*":
                    if dp_table[i][j-2]: # match zero
                        dp_table[i][j] = True
                    elif dp_table[i-1][j]: # match one or more
                        if p[j-2] == "." or p[j-2] == s[i-1]:
                            dp_table[i][j] = True
                else:
                    if dp_table[i-1][j-1]:
                        if s[i-1] == p[j-1] or p[j-1] == ".":
                            dp_table[i][j] = True

        return dp_table[-1][-1]






print(Solution().isMatch("aaaa", "a*a*"))



# print(Solution().isMatch("aa", "a"))
# print(Solution().isMatch("aa", "ab"))
# print(Solution().isMatch("aa", "aa"))
# Solution().isMatch("aa", "a*")
# Solution().isMatch("aa", "..")
# Solution().isMatch("aa", ".*")
# Solution().isMatch("aab", ".*")
# Solution().isMatch("aabaa", "a.*")
# Solution().isMatch("aabaa", ".*baa")
# Solution().isMatch("aabaa", ".*b")
