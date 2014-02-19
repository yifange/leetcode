class Solution:
    # @param A, a list of integers
    # @return an integer
    def trap(self, A):
        if len(A) == 0:
            return 0
        high = A[0]
        high_pos = 0
        i = 1
        water = 0
        obs = 0
        while i < len(A):
            if A[i] >= high:
                water += high * (i - high_pos - 1) - obs
                high = A[i]
                high_pos = i
                obs = 0
            else:
                obs += A[i]
            i += 1

        obs = 0
        highest_pos = high_pos
        high = A[-1]
        high_pos = len(A) - 1
        i = len(A) - 2
        while i >= highest_pos:
            if A[i] >= high:
                water += high * (high_pos - i - 1) - obs
                high = A[i]
                high_pos = i
                obs = 0
            else:
                obs += A[i]
            i -= 1
        return water

sol = Solution()
A = [4, 2, 3]
print sol.trap(A)

