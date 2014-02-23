class Solution:
    # @return an integer
    def minDistance(self, word1, word2):
        m = []
        for i in range(len(word1) + 1):
            m.append([0] * (len(word2) + 1))
        for i in range(len(word1) + 1):
            m[i][0] = i
        for i in range(len(word2) + 1):
            m[0][i] = i
        for s in range(2, len(word1) + len(word2) + 1):
            for i in range(1, s):
                j = s - i
                if i > 0 and i <= len(word1) and j > 0 and j <= len(word2):
                    if word1[i - 1] == word2[j - 1]:
                        m[i][j] = m[i - 1][j - 1]
                    else:
                        m[i][j] = min(m[i - 1][j] + 1, m[i][j - 1] + 1, m[i - 1][j - 1] + 1)
        return m[len(word1)][len(word2)]

sol = Solution()
word1 = "horse"
word2 = "ros"
print sol.minDistance(word1, word2)
