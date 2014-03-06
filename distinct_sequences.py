class Solution:
    # @return an integer
    def numDistinct(self, S, T):
        d = []
        for i in range(len(T)):
            d.append([0] * len(S))

        if len(T) == 0 or len(S) == 0:
            return 0
        if S[0] == T[0]:
            d[0][0] = 1

        for i in range(1, len(S)):
            if S[i] == T[0]:
                d[0][i] = d[0][i - 1] + 1
            else:
                d[0][i] = d[0][i - 1]

        for i in range(1, len(T)):
            for j in range(i, len(S)):
                if S[j] == T[i]:
                    d[i][j] = d[i][j - 1] + d[i - 1][j - 1]
                else:
                    d[i][j] = d[i][j - 1]
        return d[len(T) - 1][len(S) - 1]

sol = Solution()
S = "rabbbbit"
T = "rabbit"
print sol.numDistinct(S, T)
