class Solution:
    # @param A a list of integers
    # @return nothing, sort in place
    def sortColors(self, A):
        i = j = k = 0
        for p in range(len(A)):
            if A[p] == 0:
                A[k] = 2
                A[j] = 1
                A[i] = 0
                i += 1
                j += 1
                k += 1
            elif A[p] == 1:
                A[k] = 2
                A[j] = 1
                j += 1
                k += 1
            else:
                A[k] = 2
                k += 1
        return A
sol = Solution()
print sol.sortColors([1, 0, 1, 1, 2, 2, 0, 1, 0])


