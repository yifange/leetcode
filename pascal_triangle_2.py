class Solution:
    # @return a list of integers
    def getRow(self, rowIndex):
        row = [1]
        for i in range(rowIndex):
            row = [elem[0] + elem[1] for elem in zip([0] + row, row + [0])]
        return row
sol = Solution()
print sol.getRow(3)
