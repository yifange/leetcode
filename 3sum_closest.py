class Solution:
    # @return an integer
    def threeSumClosest(self, num, target):
        d = 32768
        closest = 0
        num.sort()
        for i in range(len(num) - 2):
            j = i + 1
            k = len(num) - 1
            while (j < k):
                s = num[i] + num[j] + num[k]
                if s - target == 0:
                    return s
                if abs(s - target) < d:
                    d = abs(s - target)
                    closest = s
                if s < target:
                    j += 1
                else:
                    k -= 1
        return closest

sol = Solution()
num = []
target = 1
print sol.threeSumClosest(num, target)
