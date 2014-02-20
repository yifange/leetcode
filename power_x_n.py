class Solution:
    # @param x, a float
    # @param n, a integer
    # @return a float
    def power(self, x, n):
        result = 1
        while (n > 0):
            if n % 2:
                result *= x
            x = x * x
            n /= 2
        return result
    def pow(self, x, n):
        if n >= 0:
            return self.power(x, n)
        else:
            return 1.0 / self.power(x, -n)
sol = Solution()
print sol.pow(34.00515, -3)
