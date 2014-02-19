class Solution:
    # @return a boolean
    def isValid(self, s):
        pairs = {")": "(", "]": "[", "}": "{"}
        stack = []
        for p in s:
            if p in ["(", "[", "{"]:
                stack.append(p)
            elif len(stack) and stack.pop() == pairs[p]:
                pass
            else:
                return False
        if not stack:
            return True
        else:
            return False

sol = Solution()
s = ")"
print sol.isValid(s)
