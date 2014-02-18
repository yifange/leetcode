class Solution:
    # @return a float
    def findKth(self, A, B, k):
        i = 0
        j = 0
        while i < len(A) and j < len(B):
            if A[i] < B[j]:
                if i + j == k - 1:
                    return A[i]
                i += 1
            else:
                if i + j == k - 1:
                    return B[j]
                j += 1
        while i < len(A):
            if i + j == k - 1:
                return A[i]
            i += 1
        while j < len(B):
            if i + j == k - 1:
                return B[j]
            j += 1
    def findMedianSortedArrays(self, A, B):
        m = len(A)
        n = len(B)
        if ((m + n) % 2 == 1):
            return float(self.findKth(A, B, (m + n) / 2 + 1))
        else:
            return (float(self.findKth(A, B, (m + n) / 2)) + self.findKth(A, B, (m + n) / 2 + 1)) / 2

sol = Solution()
A = []
B = [1, 2]
print sol.findMedianSortedArrays(A, B)

