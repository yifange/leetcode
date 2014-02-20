class Solution:
    # @param A, a list of integers
    # @return a boolean
    def canJump(self, A):
        if not A:
            return False
        farthest = 0
        i = 0
        while (i <= farthest and farthest < len(A) - 1):
            farthest = max(farthest, i + A[i])
            i += 1
        if farthest >= len(A) - 1:
            return True
        else:
            return False

sol = Solution()
A = [3, 2, 1, 0, 4]
print sol.canJump(A)
