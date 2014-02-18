class Solution:
    # @param A  a list of integers
    # @param m  an integer, length of A
    # @param B  a list of integers
    # @param n  an integer, length of B
    # @return nothing
    def merge(self, A, m, B, n):
        c = []
        i = 0
        j = 0
        while (i < m and j < n):
            if A[i] < B[j]:
                c.append(A[i])
                i += 1
            else:
                c.append(B[j])
                j += 1
        while (i < m):
            c.append(A[i])
            i += 1
        while (j < n):
            c.append(B[j])
            j += 1
        for i in range(m + n):
            A[i] = c[i]
