# https://leetcode.com/problems/maximum-points-tourist-can-earn/

from typing import List

class Solution:
    def maxScore(self, n: int, k: int, stayScore: List[List[int]], travelScore: List[List[int]]) -> int:
        dp = [[0 for _ in range(n+1)] for _ in range(k+1)]

        for i in range(k):
            for j in range(n):
                # stay
                score = stayScore[i][j]

                dp[i+1][j+1] = max(dp[i][j+1] + score, dp[i+1][j+1])
                # don't need max?
                # dp[i+1][j+1] = dp[i][j+1] + score

                # travel
                for k in range(n):
                    score = travelScore[j][k]
                    dp[i+1][k+1] = max(dp[i+1][k+1], dp[i][j+1] + score)

        print(dp)
        return max(dp[-1])



# print(Solution().maxScore(n = 2, k = 1, stayScore = [[2,3]], travelScore = [[0,2],[1,0]]))
print(Solution().maxScore(n = 3, k = 2, stayScore = [[3,4,2],[2,1,2]], travelScore = [[0,2,1],[2,0,4],[3,2,0]]))
