class Solution:
    # @param obstacleGrid, a list of lists of integers
    # @return an integer
    def uniquePathsWithObstacles(self, obstacleGrid):
        if len(obstacleGrid) == 0:
            return 0
        else:
            m = len(obstacleGrid)
            n = len(obstacleGrid[0])
        d = []
        for i in range(m):
            d.append([0] * n)
        p = True
        for i in range(n):
            if p and obstacleGrid[0][i] == 0:
                d[0][i] = 1
            elif obstacleGrid[0][i] == 1:
                p = False
        p = True
        for i in range(m):
            if p and obstacleGrid[i][0] == 0:
                d[i][0] = 1
            elif obstacleGrid[i][0] == 1:
                p = False
        if m == 1:
            return d[0][n - 1]
        if n == 1:
            return d[m - 1][0]
        for i in range(1, m):
            for j in range(1, n):
                if obstacleGrid[i][j] == 0:
                    d[i][j] = d[i - 1][j] + d[i][j - 1]
                else:
                    d[i][j] = 0
        return d[m - 1][n - 1]

sol = Solution()
obstacleGrid = [[0]]

print sol.uniquePathsWithObstacles(obstacleGrid)
