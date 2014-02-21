# Definition for a  binary tree node
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    # @param inorder, a list of integers
    # @param postorder, a list of integers
    # @return a tree node
    def buildTree(self, preorder, inorder):
        if not inorder:
            return None
        else:
            val = preorder[0]
            root = TreeNode(val)
            ind = 0
            for ind in range(len(inorder)):
                if inorder[ind] == val:
                    break
            root.left = self.buildTree(preorder[1:ind + 1], inorder[:ind])
            root.right = self.buildTree(preorder[ind + 1:], inorder[ind + 1:])
            return root

sol = Solution()
preorder = [1, 2, 3, 4, 5]
inorder = [2, 1, 4, 3, 5]
n = sol.buildTree(preorder, inorder)
