class Solution:
    # @param s, a string
    # @return a boolean
    def isNumber(self, s):
        try:
            float(s)
            return True
        except:
            return False
sol = Solution()
s = " abc"
print sol.isNumber(s)
