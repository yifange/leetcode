# Definition for a  binary tree node
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    # @param num, a list of integers
    # @return a tree node
    def convert(self, num):
        if len(num) == 0:
            return None
        elif len(num) == 1:
            return TreeNode(num[0])
        else:
            m = len(num) / 2
            root = TreeNode(num[m])
            root.left = self.convert(num[:m])
            root.right = self.convert(num[(m + 1):])
            return root

    def sortedArrayToBST(self, num):
        return self.convert(num)

sol = Solution()
num = []
root = sol.convert(num)
