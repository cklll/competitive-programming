# https://leetcode.com/problems/word-break/

from typing import List

class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        w_dict = set(wordDict)

        dp_table = [True]
        for i, char in enumerate(s):

            is_found = False
            for j in range(i+1):
                chars_to_fill = s[j:i+1]
                if dp_table[j] and chars_to_fill in w_dict:
                    is_found = True
                    break

            dp_table.append(is_found)

        return dp_table[-1]

print(Solution().wordBreak("leetcode", ["leet", "code"]))
print(Solution().wordBreak("leet", ["leet", "code"]))
print(Solution().wordBreak("leetcode", ["leet", "cod"]))
print(Solution().wordBreak("a", ["a", "b"]))
print(Solution().wordBreak("ab", ["a", "b"]))
