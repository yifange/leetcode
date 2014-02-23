# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    # @param head, a ListNode
    # @return a ListNode
    def insertionSortList(self, head):
        newhead = ListNode(-32767)
        current = head
        while current:
            nxt = current.next
            p = newhead
            while 1:
                if not p.next or p.next.val >= current.val:
                    current.next = p.next
                    p.next = current
                    break
                else:
                    p = p.next
            current = nxt
        p = newhead.next
        del newhead
        return p

sol = Solution()
n1 = ListNode(1)
n2 = ListNode(2)
n3 = ListNode(3)
n4 = ListNode(4)
n5 = ListNode(5)
n5.next = n3
n4.next = n2
n3.next = n4
n2.next = n1
p = sol.insertionSortList(n5)
while p:
    print p.val
    p = p.next

