class Solution:
    # @param an integer
    # @return a list of string
    def generate(self, stack, current, result, n):
        if not n and not stack:
            result.append(current)
            return
        if n:
            self.generate(stack + 1, current + "(", result, n - 1)
        if stack:
            self.generate(stack - 1, current + ")", result, n)

    def generateParenthesis(self, n):
        result = []
        self.generate(0, "", result, n)
        return result
