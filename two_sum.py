class Solution:
    def twoSum(self, numbers, target):
        nums = []
        for i in range(len(numbers)):
            nums.append((numbers[i], i))
        for i in range(len(numbers) - 1):
            for j in range(i + 1, len(numbers)):
                if nums[i][0] > nums[j][0]:
                    t = nums[i]
                    nums[i] = nums[j]
                    nums[j] = t

        for i in range(len(numbers) - 1):
            if nums[i][0] > target:
                break
            for j in range(i + 1, len(numbers)):
                if nums[i][0] + nums[j][0] == target:
                    if nums[i][1] < nums[j][1]:
                        return [nums[i][1] + 1, nums[j][1] + 1]
                    else:
                        return [nums[j][1] + 1, nums[i][1] + 1]

                if nums[i][0] + nums[j][0] > target:
                    break

sol = Solution()
numbers = [0, 4, 3, 0]
target = 0
print sol.twoSum(numbers, target)
