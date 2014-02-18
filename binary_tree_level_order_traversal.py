# Definition for a  binary tree node
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    # @param root, a tree node
    # @return a list of lists of integers
    def levelOrder(self, root):
        result = []
        if not root:
            return []
        result.append([root])
        i = 0
        while result[i]:
            row = []
            for p in result[i]:
                if p.left:
                    row.append(p.left)
                if p.right:
                    row.append(p.right)
            result[i] = [p.val for p in result[i]]
            if not row:
                break
            result.append(row)
            i += 1
        return result
sol = Solution()
n1 = TreeNode(1)
n2 = TreeNode(2)
n3 = TreeNode(3)
n4 = TreeNode(4)
n1.left = n2
n1.right = n3
n3.left = n4
print sol.levelOrder(n1)
