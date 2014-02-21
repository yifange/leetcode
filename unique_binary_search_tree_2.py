# Definition for a  binary tree node
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    # @return a list of tree node
    def gen(self, l, r):
        if l > r:
            return [None]
        elif l == r:
            return [TreeNode(l)]
        else:
            trees = []
            for i in range(l, r + 1):
                left_trees = self.gen(l, i - 1)
                right_trees = self.gen(i + 1, r)
                for left in left_trees:
                    for right in right_trees:
                        root = TreeNode(i)
                        root.left = left
                        root.right = right
                        trees.append(root)
            return trees

    def generateTrees(self, n):
        return self.gen(1, n)

sol = Solution()

print sol.generateTrees(3)
