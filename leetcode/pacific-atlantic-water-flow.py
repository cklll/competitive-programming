from typing import List

class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        self.m = len(heights)
        self.n = len(heights[0])
        self.directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]

        # DFS from pacific ocean and atlatic ocean

        pacific_visited = [[False for _ in range(self.n)] for _ in range(self.m)]
        atlantic_visited = [[False for _ in range(self.n)] for _ in range(self.m)]

        # pacific ocean
        for x in range(self.n): # top
            self.dfs(pacific_visited, x, 0, heights)
        for y in range(self.m): # left
            self.dfs(pacific_visited, 0, y, heights)

        # atlantic ocean
        for x in range(self.n): # bottom
            self.dfs(atlantic_visited, x, self.m-1, heights)
        for y in range(self.m): # right
            self.dfs(atlantic_visited, self.n-1, y, heights)

        result = []
        for y in range(self.m):
            for x in range(self.n):
                if pacific_visited[y][x] and atlantic_visited[y][x]:
                    result.append([y, x])

        return result

    def dfs(self, visited, x, y, heights):
        if visited[y][x]:
            return

        visited[y][x] = True

        for direction in self.directions:
            new_x = x+direction[0]
            new_y = y+direction[1]

            if new_x >= 0 and new_x <= self.n - 1 and new_y >= 0 and new_y <= self.m - 1:
                if heights[new_y][new_x] >= heights[y][x]:
                    self.dfs(visited, new_x, new_y, heights)
