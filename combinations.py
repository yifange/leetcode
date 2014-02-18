class Solution:
    # @return a list of lists of integers
    def solve(self, number, n, k, results, current):
        if number <= n + 1:
            if k == 0:
                results.append(current)
            else:
                self.solve(number + 1, n, k - 1, results, current + [number])
                self.solve(number + 1, n, k, results, current)

    def combine(self, n, k):
        results = []
        self.solve(1, n, k, results, [])
        return results

sol = Solution()
n = 4
k = 3
print sol.combine(n, k)
