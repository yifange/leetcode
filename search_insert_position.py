class Solution:
    # @param A, a list of integers
    # @param target, an integer to be inserted
    # @return integer
    def searchInsert(self, A, target):
        if len(A) == 0:
            return 0
        if target <= A[0]:
            return 0
        if target > A[-1]:
            return len(A)
        i = 1
        while i < len(A):
            if A[i] == target:
                return i
            elif A[i] < target:
                i += 1
            else:
                return i

sol = Solution()
A = [1, 3, 5, 6]
target = 0
print sol.searchInsert(A, target)
