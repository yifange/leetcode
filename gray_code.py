class Solution:
    # @return a list of integers
    def grayCode(self, n):
        codes = []
        for i in range(2 ** n):
            base = 1
            code = 0
            for j in range(n):
                bit = 0
                if i < 2 ** j:
                    bit = 0
                elif ((i - 2 ** j) / (2 ** (j + 1))) % 2 == 1:
                    bit = 0
                else:
                    bit = 1
                code += base * bit
                base *= 2
            codes.append(code)
        return codes
sol = Solution()
n = 3
print sol.grayCode(n)
