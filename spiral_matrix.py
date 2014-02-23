class Solution:
    # @param matrix, a list of lists of integers
    # @return a list of integers
    def spiralOrder(self, matrix):
        if not matrix:
            return []
        m = len(matrix)
        n = len(matrix[0])
        a = [0] * (m * n)
        i = j = k = 0
        left = top = 0
        right = n
        bottom = m
        while k < m * n:
            if left == right - 1 and top == bottom - 1:
                a[k] = matrix[top][left]
                k += 1
            for i in range(left, right - 1):
                if k < m * n:
                    a[k] = matrix[top][i]
                    k += 1
            for i in range(top, bottom - 1):
                if k < m * n:
                    a[k] = matrix[i][right - 1]
                    k += 1
            for i in range(right - 1, left, -1):
                if k < m * n:
                    a[k] = matrix[bottom - 1][i]
                    k += 1
            for i in range(bottom - 1, top, -1):
                if k < m * n:
                    a[k] = matrix[i][left]
                    k += 1
            left += 1
            top += 1
            right -= 1
            bottom -= 1
        return a
sol = Solution()
matrix = [
]
print sol.spiralOrder(matrix)
