# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    # @param head, a ListNode
    # @param m, an integer
    # @param n, an integer
    # @return a ListNode
    def reverseList(self, head):
        p = head
        q = p.next
        while q:
            t = q.next
            q.next = p
            p = q
            q = t
        head.next = None
        return p

    def reverseBetween(self, head, m, n):
        fake_head = ListNode(-1)
        fake_head.next = head
        head_last = fake_head
        for i in xrange(m - 1):
            head_last = head_last.next
        h = head_last.next
        t = h
        for i in range(n - m):
            t = t.next
        tail_first = t.next
        t.next = None
        h = self.reverseList(h)
        t = h
        while (t.next):
            t = t.next
        t.next = tail_first
        head_last.next = h
        head = fake_head.next
        del fake_head
        return head

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
head = sol.reverseBetween(n1, 1, 4)
# head = sol.reverseList(n1)
while head:
    print head.val
    head = head.next


