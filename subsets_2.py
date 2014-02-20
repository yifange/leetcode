class Solution:
    # @param num, a list of integer
    # @return a list of lists of integer
    def solve(self, numbers, current, results):
        if not numbers:
            results.append(current)
        else:
            number = numbers[0][0]
            for i in range(numbers[0][1] + 1):
                self.solve(numbers[1:], current + [number] * i, results)

    def subsetsWithDup(self, S):
        number_hash = {}
        for i in S:
            if i in number_hash:
                number_hash[i] += 1
            else:
                number_hash[i] = 1
        numbers = number_hash.items()
        numbers.sort()
        results = []
        self.solve(numbers, [], results)
        return results

sol = Solution()
S = [1, 2, 2]
print sol.subsetsWithDup(S)
