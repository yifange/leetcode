class Solution:
    # @return an integer
    def maxArea(self, height):
        l = 0
        r = len(height) - 1
        m = (r - l) * min(height[l], height[r])
        while l < r:
            if height[l] < height[r]:
                i = l + 1
                while i < len(height) and height[i] <= height[l]:
                    i += 1
                if i == len(height):
                    break
                l = i
            else:
                j = r - 1
                while j >= 0 and height[j] <= height[r]:
                    j -= 1
                if j < 0:
                    break
                r = j
            m = max(m, (r - l) * min(height[l], height[r]))
        return m
sol = Solution()
height = [1, 1]
print sol.maxArea(height)

