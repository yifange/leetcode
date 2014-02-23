class Solution:
    # @param s, a string
    # @return a list of lists of string
    def solve(self, i, current, results):
        if i >= len(self.s):
            results.append(current)
        else:
            for d in self.jump_list[i]:
                self.solve(i + d + 1, current + [self.s[i:i + d + 1]], results)

    def partition(self, s):
        palin_m = []
        for i in range(len(s)):
            palin_m.append([False] * len(s))
        for i in range(len(s)):
            palin_m[i][i] = True

        for l in range(1, len(s)):
            for i in range(len(s) - l):
                j = i + l
                if s[i] == s[j] and (j == i + 1 or palin_m[i + 1][j - 1]):
                    palin_m[i][j] = True
        self.jump_list = []
        for i in range(len(palin_m)):
            current = []
            for j in range(len(palin_m[i])):
                if palin_m[i][j]:
                    current.append(j - i)
            self.jump_list.append(current)

        results = []
        self.s = s
        self.solve(0, [], results)
        return results

sol = Solution()
s = "a"
print sol.partition(s)

