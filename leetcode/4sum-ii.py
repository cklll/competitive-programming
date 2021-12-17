# https://leetcode.com/problems/4sum-ii/submissions/

# Runtime: 784 ms, faster than 56.29% of Python3 online submissions for 4Sum II.
# Memory Usage: 14.7 MB, less than 21.93% of Python3 online submissions for 4Sum II.


class Solution:
    def fourSumCount(self, nums1: List[int], nums2: List[int], nums3: List[int], nums4: List[int]) -> int:
        list_a = {}
        for n1 in nums1:
            for n2 in nums2:
                s = n1+n2
                if s in list_a:
                    list_a[s] += 1
                else:
                    list_a[s] = 1

        list_b = {}
        for n3 in nums3:
            for n4 in nums4:
                s = n3+n4
                if s in list_b:
                    list_b[s] += 1
                else:
                    list_b[s] = 1

        result = 0
        for n, counter in list_a.items():
            if -n not in list_b:
                continue

            result += counter * list_b[-n]

        return result



# idea
# sum nums1 and nums2 to one list
# sum nums3 and nums4 to one list

# sort the 2 new list
# then iterate list_a, then search the other pair in list_b.

# we will use dict. Becuase it will be more efficient to handle duplicate
