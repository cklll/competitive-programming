# https://leetcode.com/problems/set-matrix-zeroes/

from typing import List

class Solution:
    def changePrevNeighbours(self, matrix, x, y):
        # change column
        for i in range(x):
            matrix[i][y] = 0

        # change row
        for i in range(y):
            matrix[x][i] = 0

    def changeAfterRowCells(self, matrix, x, y):
        for i in range(y+1, len(matrix[0])):
            matrix[x][i] = 0

    def changeAfterColumnCells(self, matrix, x, y):
        for i in range(x+1, len(matrix)):
            matrix[i][y] = 0


    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """

        # first pass. scan from top left to bottom right
        # if 0, mark the cell on the left and above to 0

        # second pass, scan again
        # if this is 0, and the right is 1, whole row 0
        # AND if this is 0 and the top is 1, whole column 0


        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                if matrix[i][j] == 0:
                    self.changePrevNeighbours(matrix, i, j)


        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                if j < len(matrix[0])-1 and matrix[i][j] == 0 and matrix[i][j+1] == 1:
                    self.changeAfterRowCells(matrix, i, j)

                if i < len(matrix)-1 and matrix[i][j] == 0 and matrix[i+1][j] == 1:
                    self.changeAfterColumnCells(matrix, i, j)

        return matrix


print(Solution().setZeroes([[1,1,1],[1,0,1],[1,1,1]]))
# Solution().setZeroes([[0,1,2,0],[3,4,5,2],[1,3,1,5]])
