# https://leetcode.com/problems/unique-paths/

class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        result = [[1] * n]

        for i in range(1, m):
            result.append([0] * n)
            for j in range(n):
                result[i][0] = 1

        for i in range(1, m):
            for j in range(1, n):
                result[i][j] = result[i-1][j] + result[i][j-1]

        print(result[m-1][n-1])


Solution().uniquePaths(1, 1)
Solution().uniquePaths(1, 2)
Solution().uniquePaths(2, 1)
Solution().uniquePaths(2, 2)
Solution().uniquePaths(2, 3)
Solution().uniquePaths(3, 2)
Solution().uniquePaths(3, 3)

Solution().uniquePaths(7, 3)




# 1 1 1 1
# 1 2 3 4
# 1 3


# xxx
# xxx
# xxx
