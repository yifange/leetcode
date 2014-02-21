class Solution:
    # @return a list of strings, [s1, s2]

    def solve(self, digits, current, results):
        if not digits:
            results.append(current)
        else:
            d = int(digits[0])
            for c in self.table[int(d)]:
                self.solve(digits[1:], current + c, results)

    def letterCombinations(self, digits):
        self.table = ["", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"]
        results = []
        self.solve(digits, "", results)
        return results

sol = Solution()
print sol.letterCombinations("23")
