class Solution:
    # @param A a list of integers
    # @return an integer

    def removeDuplicates(self, A):
        if not len(A):
            return 0
        i = 0
        d = 0
        last = A[0] - 1
        while i + d < len(A):
            A[i] = A[i + d]
            if A[i] == last:
                while i + d + 1 < len(A) and A[i + d + 1] == last:
                    d += 1
            last = A[i]
            i += 1
        return i

sol = Solution()
A = [0, 0,0, 0]
print sol.removeDuplicates(A)

