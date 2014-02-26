class Solution:
    # @param A, a list of integers
    # @return an integer
    # def jump(self, A):
    #     d = [32767] * len(A)
    #     d[0] = 0
    #     for i in range(len(A)):
    #         for j in range(1, A[i] + 1):
    #             if i + j < len(A):
    #                 d[i + j] = min(d[i + j], d[i] + 1)
    #     return d[len(A) - 1]
    def jump(self, A):
        max_dist = 0
        steps = 0
        next_step = 0
        i = 0
        while i < len(A):
            if i > next_step:
                steps += 1
                next_step = max_dist
            max_dist = max(max_dist, i + A[i])
            i += 1
        return steps

sol = Solution()
A = [1]
print sol.jump(A)
