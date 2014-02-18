class Solution:
    # @return a list of lists of integers
    def generate(self, numRows):
        triangle = []
        if numRows > 0:
            triangle.append([1])
            for i in range(1, numRows):
                r = triangle[i - 1]
                triangle.append([e[0] + e[1] for e  in zip([0] + r, r + [0])])
        return triangle
sol = Solution()
print sol.generate(4)
