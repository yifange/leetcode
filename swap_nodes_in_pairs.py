# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    # @param a ListNode
    # @return a ListNode
    def swapPairs(self, head):
        if not head:
            return head
        if not head.next:
            return head

        phead = ListNode(0)
        phead.next = head
        p = phead
        q = p.next
        r = q.next
        while 1:
            p.next = r
            q.next = r.next
            r.next = q
            p = q
            if not p:
                break

            q = p.next
            if not q:
                break
            r = q.next
            if not r:
                break
        return phead.next

sol = Solution()
n1 = ListNode(1)
n2 = ListNode(2)
n3 = ListNode(3)
n4 = ListNode(4)
# n1.next = n2
# n2.next = n3
# n3.next = n4
head = sol.swapPairs(None)
while (head):
    print head.val
    head = head.next
