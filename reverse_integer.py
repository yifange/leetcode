class Solution:
    # @return an integer
    def reverse(self, x):
        neg = 1
        if x < 0:
            neg = -1
            x = -x

        s = str(x)
        return neg * int(s[::-1])
sol = Solution()
print sol.reverse(-1230)
