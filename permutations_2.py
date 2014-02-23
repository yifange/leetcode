class Solution:
    # @param num, a list of integer
    # @return a list of lists of integers

    def solve(self, h, last, current, results):

        if len(current) == self.n:
            results.append(current)
        else:
            for num in h.keys():
                if h[num] and num != last:
                    for t in range(1, h[num] + 1):
                        h[num] -= t
                        self.solve(h, num, current + [num] * t, results)
                        h[num] += t

    def permuteUnique(self, num):
        if not num:
            return []
        h = {}
        for i in num:
            if i in h.keys():
                h[i] += 1
            else:
                h[i] = 1

        results = []
        self.n = len(num)
        self.solve(h, min(num) - 1, [], results)
        return results

sol = Solution()
num = []
print sol.permuteUnique(num)
