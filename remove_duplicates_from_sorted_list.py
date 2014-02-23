# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    # @param head, a ListNode
    # @return a ListNode
    def deleteDuplicates(self, head):
        if not head:
            return head
        fake_head = ListNode(head.val - 1)
        fake_head.next = head
        q = fake_head
        p = head
        while p:
            t = p.next
            to_del = False
            while t and t.val == p.val:
                t = t.next
                to_del = True
            if to_del:
                q.next = t
                p = t
            else:
                q = p
                p = p.next
        head = fake_head.next
        del fake_head
        return head

sol = Solution()
n1 = ListNode(1)
n2 = ListNode(1)
n3 = ListNode(1)
n4 = ListNode(3)
n5 = ListNode(4)
n6 = ListNode(4)
n7 = ListNode(5)
n1.next = n2
n2.next = n3
n3.next = n4
n4.next = n5
n5.next = n6
n6.next = n7
p = sol.deleteDuplicates(n1)
while p:
    print p.val
    p = p.next


