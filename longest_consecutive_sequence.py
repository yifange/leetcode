class Solution:
    # @param num, a list of integer
    # @return an integer
    def longestConsecutive(self, num):
        h = {}
        m = 0
        for i in num:
            if i in h:
                continue
            left = right = i
            if (i - 1) in h:
                left = h[i - 1][0]

            if (i + 1) in h:
                right = h[i + 1][1]

            h[i] = [left, right]
            h[left][1] = right
            h[right][0] = left
            if right - left + 1 > m:
                m = right - left + 1
        return m

sol = Solution()
num = [-1,9,-3,-6,7,-8,-6,2,9,2,3,-2,4,-1,0,6,1,-9,6,8,6,5,2]
print sol.longestConsecutive(num)
