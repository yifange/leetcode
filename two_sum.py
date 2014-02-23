class Solution:
    def twoSum(self, numbers, target):
        nums = []
        for i in range(len(numbers)):
            nums.append((numbers[i], i))
        nums.sort()
        i = 0
        j = len(nums) - 1
        while i < j:
            if nums[i][0] + nums[j][0] < target:
                i += 1
            elif nums[i][0] + nums[j][0] > target:
                j -= 1
            else:
                r = [nums[i][1] + 1, nums[j][1] + 1]
                r.sort()
                return r
        return [-1, -1]
sol = Solution()
numbers = [3, 2, 4]
target = 6
print sol.twoSum(numbers, target)
