class Solution:
    # @param A a list of integers
    # @param target an integer
    # @return a boolean
    def binary_search(self, A, l, r, target):
        if l > r:
            return False
        m = (l + r) / 2
        if A[m] == target:
            return True
        else:
            left = self.binary_search(A, l, m - 1, target)
            if left:
                return True
            right = self.binary_search(A, m + 1, r, target)
            return right

    def rotated_search(self, A, l, r, target):
        while A[l] == A[r] and l < r:
            if A[l] == target:
                return True
            else:
                l += 1
                r -= 1
        if l > r:
            return False
        m = (l + r) / 2
        if A[m] == target:
            return True
        else:
            if A[l] >= A[m]:
                left = self.rotated_search(A, l, m - 1, target)
                if left:
                    return True
                right = self.binary_search(A, m + 1, r, target)
                return right
            elif A[m] >= A[r]:
                left = self.binary_search(A, l, m - 1, target)
                if left:
                    return True
                right = self.rotated_search(A, m + 1, r, target)
                return right
            else:
                left = self.binary_search(A, l, m - 1, target)
                if left:
                    return True
                right = self.binary_search(A, m + 1, r, target)
                return right

    def search(self, A, target):
        if len(A) == 0:
            return False
        return self.rotated_search(A, 0, len(A) - 1, target)


sol = Solution()
A = [1, 3, 5, 7]
print sol.search(A, 0)
