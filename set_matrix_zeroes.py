class Solution:
    # @param matrix, a list of lists of integers
    # RETURN NOTHING, MODIFY matrix IN PLACE.
    def setZeroes(self, matrix):
        m = len(matrix)
        n = len(matrix[0])
        zero = False
        if m == 1:
            for c in matrix[0]:
                if c == 0:
                    zero = True
                    break
            if zero:
                for i in range(n):
                    matrix[0][i] = 0
            return
        zero = False
        if n == 1:
            for i in range(m):
                if matrix[i][0] == 0:
                    zero = True
                    break
            if zero:
                for i in range(m):
                    matrix[i][0] = 0
            return
        row_zero = False
        col_zero = False
        for i in range(n):
            if matrix[0][i] == 0:
                row_zero = True
        for i in range(m):
            if matrix[i][0] == 0:
                col_zero = True

        for i in range(1, m):
            for j in range(1, n):
                if matrix[i][j] == 0:
                    matrix[0][j] = 0
                    matrix[i][0] = 0

        for i in range(1, m):
            for j in range(1, n):
                if matrix[0][j] == 0 or matrix[i][0] == 0:
                    matrix[i][j] = 0
        for i in range(n):
            if row_zero:
                matrix[0][i] = 0
        for i in range(m):
            if col_zero:
                matrix[i][0] = 0

sol = Solution()
matrix = [[3,3,3,5],[4,3,1,4],[0,1,1,4],[1,2,1,3],[0,0,1,1]]
sol.setZeroes(matrix)
print matrix
