class Solution:
    # @return an integer

    def solve(self, i, n, result):
        if (i == n):
            self.count += 1
        else:
            for j in range(n):
                ok = True
                for k in range(i):
                    if j == result[k] or abs(j - result[k]) == abs(i - k):
                        ok = False
                if ok:
                    self.solve(i + 1, n, result + [j])

    def totalNQueens(self, n):
        self.count = 0
        self.solve(0, n, [])
        return self.count
sol = Solution()
print sol.totalNQueens(0)
