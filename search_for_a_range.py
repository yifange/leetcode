class Solution:
    # @param A, a list of integers
    # @param target, an integer to be searched
    # @return a list of length 2, [index1, index2]
    def findLeft(self, A, target):
        left = 0
        right = len(A) - 1
        while left <= right:
            mid = (left + right) / 2
            if A[mid] < target:
                left = mid + 1
            else:
                right = mid - 1

        if left < len(A) and left >= 0 and A[left] == target:
            return left
        else:
            return -1

    def findRight(self, A, target):
        left = 0
        right = len(A) - 1
        while left <= right:
            mid = (left + right) / 2
            if target < A[mid]:
                right = mid - 1
            else:
                left = mid + 1

        if right >= 0 and right < len(A) and A[right] == target:
            return right
        else:
            return -1

    def searchRange(self, A, target):
        return [self.findLeft(A, target), self.findRight(A, target)]

sol = Solution()
A = [1]
print sol.searchRange(A, 1)
