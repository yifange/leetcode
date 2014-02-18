class Solution:
    # @param grid, a list of lists of integers
    # @return an integer
    def minPathSum(self, grid):
        d = []
        m = len(grid)
        if m == 0:
            return 0
        n = len(grid[0])
        for i in range(m):
            d.append([0] * n)
        sum = 0
        for j in range(n):
            sum += grid[0][j]
            d[0][j] = sum
        sum = 0
        for i in range(m):
            sum += grid[i][0]
            d[i][0] = sum
        if m == 1 or n == 1:
            return d[m - 1][n - 1]
        for i in range(1, m):
            for j in range(1, n):
                d[i][j] = min(d[i - 1][j], d[i][j - 1]) + grid[i][j]
        return d[m - 1][n - 1]
sol = Solution()
grid = [
    [1, 2, 3],
]
print sol.minPathSum(grid)
