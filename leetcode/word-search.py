# https://leetcode.com/problems/word-search/

from typing import List

class Solution:
    directions = [
        (-1, 0), (1, 0), (0, -1), (0, 1)
    ]
    def exist(self, board: List[List[str]], word: str) -> bool:
        for i in range(len(board)):
            for j in range(len(board[0])):
                if word[0] == board[i][j]:
                    if self.dfs(board, word, i, j):
                        return True
        return False

    def dfs(self, board, word, i, j):
        if word[0] != board[i][j]:
            return False
        if len(word) == 1:
            return True

        tmp = board[i][j]
        board[i][j] = '#'

        for direction in self.directions:
            i2, j2 = i+direction[0], j+direction[1]
            if i2 >= 0 and i2 < len(board) and j2 >= 0 and j2 < len(board[0]):
                if self.dfs(board, word[1:], i2, j2):
                    return True
        board[i][j] = tmp
        return False



print(Solution().exist([["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], "ABCCED")) # true
print(Solution().exist([["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], "SEE")) # true
print(Solution().exist([["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], "ABCB")) # false
print(Solution().exist([["A","B","C","E"],["S","F","E","S"],["A","D","E","E"]], "ABCESEEEFS")) # true
print(Solution().exist([["a","a","a","a"],["a","a","a","a"],["a","a","a","a"]], "aaaaaaaaaaaaa")) # false
