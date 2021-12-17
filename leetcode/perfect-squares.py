# https://leetcode.com/problems/perfect-squares/


import math

class Solution:
    current_min = 1001

    def numSquares(self, n: int) -> int:
        self.dfs(n, 0)
        return self.current_min

    def dfs(self, current, counter):
        if current == 0:
            if counter < self.current_min:
                self.current_min = counter
            return

        if counter > self.current_min:
            return

        # try the largest perfect square first.
        perfect_square_root = int(math.sqrt(current))

        for i in range(perfect_square_root, 0, -1):
            perfect_square = i * i

            # optimize to prevent triggering 1+1+1+1+1.......
            if perfect_square * self.current_min <= current:
                break

            self.dfs(current-perfect_square, counter+1)



print(Solution().numSquares(12))
