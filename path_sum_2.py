# Definition for a  binary tree node
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    # @param root, a tree node
    # @param sum, an integer
    # @return a list of lists of integers
    def solve(self, root, sum, current, result):
        if not root.left and not root.right:
            if root.val == sum:
                result.append(current + [root.val])
        if root.left:
            self.solve(root.left, sum - root.val, current + [root.val], result)
        if root.right:
            self.solve(root.right, sum - root.val, current + [root.val], result)

    def pathSum(self, root, sum):
        result = []
        if root:
            self.solve(root, sum, [], result)
        return result

sol = Solution()
n5 = TreeNode(5)
n4 = TreeNode(4)
n3 = TreeNode(3)
n1 = TreeNode(1)
# n5.left = n4
# n5.right = n3
# n3.left = n1

print sol.pathSum([], 9)
