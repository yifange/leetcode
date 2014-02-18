# IV = 4, IX = 9, XL = 40, XC = 90, CD = 400, CM = 900
class Solution:
    # @return an integer
    def romanToInt(self, s):
        table = {"I": 1, "V": 5, "X": 10, "L": 50, "C": 100, "D": 500, "M": 1000}
        val = 0
        for i in range(len(s) - 1):
            cur = table[s[i]]
            nxt = table[s[i + 1]]
            if cur >= nxt:
                val += cur
            else:
                val -= cur
        val += table[s[len(s) - 1]]
        return val

sol = Solution()
s = "MCMX"
print sol.romanToInt(s)
