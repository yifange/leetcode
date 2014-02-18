class Solution:
    # @param a list of integers
    # @return an integer
    def removeDuplicates(self, A):
        d = 0
        i = 0
        while (i + d < len(A)):

            A[i] = A[i + d]
            while i + d + 1 < len(A) and A[i] == A[i + d + 1]:
                d += 1
            i += 1
        # print A[:i]
        return i
sol = Solution()
A = [1, 1, 2, 2, 3, 3, 3, 3]
print sol.removeDuplicates(A)
