from collections import deque


class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        n = len(grid)
        m = len(grid[0])

        pq = deque()

        visited = [[-1 for _ in range(m)] for _ in range(n)]

        for i in range(n):
            for j in range(m):
                if grid[i][j] == 2:
                    pq.append(((i, j), 0))
                    visited[i][j] = 2
                else:
                    visited[i][j] = 0

        maxi = 0
        direction = [[1, 0], [0, 1], [-1, 0], [0, -1]]
        while pq:
            (i, j), t = pq.popleft()
            maxi = max(maxi, t)

            for di, dj in direction:
                ni, nj = i + di, j + dj
                if (
                    0 <= ni < n
                    and 0 <= nj < m
                    and grid[ni][nj] == 1
                    and visited[ni][nj] == 0
                ):
                    pq.append(((ni, nj), t + 1))
                    visited[ni][nj] = 2

        for i in range(n):
            for j in range(m):
                if visited[i][j] == 0 and grid[i][j] == 1:
                    return -1

        return maxi
