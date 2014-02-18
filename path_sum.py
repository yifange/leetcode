# Definition for a  binary tree node
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    # @param root, a tree node
    # @param sum, an integer
    # @return a boolean
    def hasPathSum(self, root, sum):
        if not root:
            return False
        if not root.left and not root.right:
            if root.val == sum:
                return True
            else:
                return False
        else:
            left = right = False
            if root.left:
                left = self.hasPathSum(root.left, sum - root.val)
            if root.right:
                right = self.hasPathSum(root.right, sum - root.val)
            return left or right


sol = Solution()
n5 = TreeNode(5)
n8 = TreeNode(8)
n4 = TreeNode(4)
n11 = TreeNode(11)
n13 = TreeNode(13)
n7 = TreeNode(7)
n2 = TreeNode(2)
n1 = TreeNode(1)
n5.left = n4
n5.right = n8
n4.left = n11
n11.left = n7
n11.right = n2
n8.left = n13
n8.right = n1
print sol.hasPathSum(n5, 22)


