class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    # @param root, a tree node
    # @return a list of integers
    def traverse(self, root, result):
        if root:
            result.append(root.val)
            self.traverse(root.left, result)
            self.traverse(root.right, result)

    def preorderTraversal(self, root):
        result = []
        self.traverse(root, result)
        return result

sol = Solution()
n1 = TreeNode(1)
n2 = TreeNode(2)
n3 = TreeNode(3)
n1.right = n2
n2.left = n3
print sol.preorderTraversal(n1)
