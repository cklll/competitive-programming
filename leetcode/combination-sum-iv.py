from typing import List

class Solution:
    def combinationSum4(self, nums: List[int], target: int) -> int:
        dp_result = []
        dp_result.append(1) # if target==0

        for i in range(target):
            dp_result.append(0)
            for num in nums:
                idx = (i+1) - num
                if idx >= 0:
                    dp_result[-1] += dp_result[idx]

        # print(dp_result)
        return dp_result[-1]


print(Solution().combinationSum4([1,2,3], 4))
print(Solution().combinationSum4([1,2,3], 1))
print(Solution().combinationSum4([1], 1))
print(Solution().combinationSum4([3], 1))
