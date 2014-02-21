class Solution:
    # @return a list of lists of string

    def gen(self, a, n):
        return ["." * e + "Q" + "." * (n - e - 1) for e in a]

    def solve(self, i, n, current, results):
        if i == n:
            results.append(["." * e + "Q" + "." * (n - e - 1) for e in current])
        else:
            for j in range(n):
                ok = True
                for k in range(i):
                    if j == current[k] or abs(j - current[k]) == abs(i - k):
                        ok = False
                if ok:
                    self.solve(i + 1, n, current + [j], results)

    def solveNQueens(self, n):
        results = []
        self.solve(0, n, [], results)
        return results
        pass

sol = Solution()
print sol.solveNQueens(4)
