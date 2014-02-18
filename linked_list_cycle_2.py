# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    # @param head, a ListNode
    # @return a list node
    def detectCycle(self, head):
        q = p = head
        while (p and q):
            p = p.next
            q = q.next
            if (not q or not p):
                return None
            q = q.next
            if (not q):
                return None
            if p == q:
                break
        p = head
        while (p != q):
            p = p.next
            q = q.next
        return p
sol = Solution()
n1 = ListNode(1)
n2 = ListNode(2)
n3 = ListNode(3)
n4 = ListNode(4)
n5 = ListNode(5)
n1.next = n2
n2.next = n3
n3.next = n4
n4.next = n5
n5.next = n4
print sol.detectCycle(n1).val
