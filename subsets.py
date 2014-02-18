class Solution:
    # @param S, a list of integer
    # @return a list of lists of integer
    def subsets(self, S):
        S.sort()
        n = len(S)
        subsets = []
        for i in range(2 ** n):
            k = i
            j = 0
            subset = []
            while k:
                if k % 2:
                    subset.append(S[j])
                k /= 2
                j += 1
            subsets.append(subset[:])
        return subsets

sol = Solution()
print sol.subsets([1, 2, 3])
