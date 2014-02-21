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
    def buildTree(self, inorder, postorder):
        if not inorder:
            return None
        else:
            val = postorder[-1]
            root = TreeNode(val)
            ind = 0
            for ind in range(len(inorder)):
                if inorder[ind] == val:
                    break
            root.left = self.buildTree(inorder[:ind], postorder[:ind])
            root.right = self.buildTree(inorder[ind + 1:], postorder[ind:-1])
            return root

sol = Solution()
inorder = [2, 1, 4, 3, 5]
postorder = [2, 4, 5, 3, 1]
n = sol.buildTree(inorder, postorder)
