# https://leetcode.com/problems/longest-mountain-in-array/

from typing import List
from collections import defaultdict


class Solution:
    def longestMountain(self, arr: List[int]) -> int:
        result = 0

        up = None

        for i in range(1, len(arr)):
            # print(f'{i} {up}')
            if arr[i] > arr[i-1]:
                if up is None:
                    up = i-1
            else:
                # print("bye")
                if up is not None and arr[i] < arr[i-1]:
                    result = max(result, i - up + 1)

                if arr[i] == arr[i-1]:
                    up = None

                if i < len(arr) - 1:
                    # print('????')
                    # print(f'!!!! {arr[i+1]} {arr[i]}')
                    if arr[i+1] >= arr[i]:
                        up = None

        return result

print(Solution().longestMountain([0,1,2,3,4,5,4,3,2,1,0]))
print(Solution().longestMountain([48,62,39]))
print(Solution().longestMountain([0,2,0,2,1,2,3,4,4,1]))
