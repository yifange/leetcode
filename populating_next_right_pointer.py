# Definition for a  binary tree node
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
        self.next = None

class Solution:
    # @param root, a tree node
    # @return nothing
    def connect(self, root):
        q = [[], []]
        lvl = 0
        q[0].append(root)
        while (1):
            cont = False
            for p in q[lvl]:
                if p:
                    cont = True
                    q[1 - lvl].append(p.left)
                    q[1 - lvl].append(p.right)
            q[lvl] = []
            if not cont:
                break
            lvl = 1 - lvl
            for i in range(len(q[lvl]) - 1):
                if q[lvl][i]:
                    q[lvl][i].next = q[lvl][i + 1]

sol = Solution()
n1 = TreeNode(1)
n2 = TreeNode(2)
n3 = TreeNode(3)
n4 = TreeNode(4)
n5 = TreeNode(5)
n6 = TreeNode(6)
n7 = TreeNode(7)
n1.left = n2
n1.right = n3
n2.left = n4
n2.right = n5
n3.left = n6
n3.right = n7
sol.connect(n1)

