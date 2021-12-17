# https://leetcode.com/problems/palindrome-partitioning/submissions/

# Runtime: 628 ms, faster than 95.66% of Python3 online submissions for Palindrome Partitioning.
# Memory Usage: 29.7 MB, less than 58.35% of Python3 online submissions for Palindrome Partitioning.

class Solution:
    def partition(self, s: str) -> List[List[str]]:
        # base case
        previous_result = [[s[0]]]

        for i in range(1, len(s)):
            new_char = s[i]

            new_result = []
            # (1)
            for partition in previous_result:
                new_partition = partition + [new_char]
                new_result.append(new_partition)

            # (2) & (3)
            for partition in previous_result:
                previous_palindrome = partition[-1]

                # (2)
                if new_char * len(previous_palindrome) == previous_palindrome:
                    new_partition = partition + [] # clone list
                    new_partition[-1] = new_partition[-1] + new_char
                    new_result.append(new_partition)
                # (3)
                else:
                    if len(partition) == 1:
                        continue
                    if len(partition[-2]) == 1:
                        if partition[-2][-1] == new_char:
                            new_partition = partition + [] # clone list
                            new_palindrome = partition[-2] + partition[-1] + new_char
                            new_partition =  partition[:-2] + [new_palindrome]
                            new_result.append(new_partition)


            previous_result = new_result

        return previous_result





# # DP
# # Given
# "aab"
# [
#     ["a","a","b"],
#     ["aa","b"],
# ]

# # Then
# "aabb"
# [
#     # (1) obvious new case
#     ["a","a","b", "b"],
#     ["aa","b", "b"],

#     # (2) try to merge the previous palindrome (only works if the previous palindrome is all same characters)
#     ["a","a","bb"],
#     ["aa","bb"],
# ]


# "aabba"
# [
#     # obvious new case
#     ["a","a","b", "b", "a"],
#     ["aa","b", "b", "a"],
#     ["a","a","bb", "a"],
#     ["aa","bb", "a"],

#     # try to merge with previous palindrome, none valid

#     # (3) there is another pair
#     ["a","abba"],
#     # it's derived by (new character) + (previous palindrome) + (the character before previous palindrome)
# ]



# edge case!!
# Given "aa"
# [
#     ["a", "a"],
#     ["aa"],
# ]

# Then "aaa"
# [
#     ["a", "a", "a"],

#     # from (2)
#     ["aaa"],

#     # from (1)
#     ["aaa"], # !!!duplicate!!!
# ]

# Solution: if (2) valid, then skip (1)
