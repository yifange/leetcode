# Definition for singly-linked list with a random pointer.
class RandomListNode:
    def __init__(self, x):
        self.label = x
        self.next = None
        self.random = None

class Solution:
    # @param head, a RandomListNode
    # @return a RandomListNode
    def copyRandomList(self, head):
        if not head:
            return None
        p = head
        while p:
            p2 = RandomListNode(p.label)
            p2.next = p.next
            p.next = p2
            p = p2.next
        p = head
        while p:
            p2 = p.next
            if p.random:
                p2.random = p.random.next
            p = p2.next
        head2 = head.next
        p = head
        while p.next:
            p2 = p.next
            p.next = p2.next
            p = p2
        return head2

sol = Solution()
n1 = RandomListNode(1)
n2 = RandomListNode(2)
n3 = RandomListNode(3)
n4 = RandomListNode(4)
# n1.next = n2
# n2.next = n3
# n3.next = n4
# n1.random = n3
# n2.random = n1
# n3.random = n2
# n4.random = n1
head = sol.copyRandomList(n1)
p = head
while p:
    print p.label, ", ", p.random and p.random.label
    p = p.next
