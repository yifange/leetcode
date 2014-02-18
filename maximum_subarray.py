class Solution:
    # @param A, a list of integers
    # @return an integer
    def maxSubArray(self, A):
        d = [0] * len(A)
        d[0] = A[0]
        m = d[0]
        for i in range(1, len(A)):
            if d[i - 1] > 0:
                d[i] = d[i - 1] + A[i]
            else:
                d[i] = A[i]
            if d[i] > m:
                m = d[i]
        return m
sol = Solution()
A = [-2,1,-3,4,-1,2,1,-5,4]
print sol.maxSubArray(A)

