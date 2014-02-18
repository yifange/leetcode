#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* reverse(ListNode *p, ListNode *q, int k) {
      if (k == 1)
        return p;
      if (k == 2) {
        p->next = q->next;
        q->next = p;
        return q;
      }

      // ListNode *tail = q->next;
      // q->next = NULL;
      // ListNode *t = p->next;
      // cout << "p: " << p->val << endl << "q: " << q->val << endl;
      // cout << "reverse" << endl;
      // while (k) {
      //   p->next = q->next;
      //   q->next = p;
      //   q = p;
      //   p = t;
      //   t = p->next;
      //   k--;
      // }

    }
    ListNode *reverseKGroup(ListNode *head, int k) {
      ListNode *p = head, *q = head; 
      int i = k - 1;
      while (i > 0 && q) {
        q = q->next;
        i--;
      }
      if (q)
        head = reverse(p, q, k);
      // while (q) {
      //   p = q->next;
      //   q = p;
      //   i = k - 1;
      //   while (i > 0 && q) {
      //      q = q->next;
      //      i--;
      //   }
      //   if (q)
      //     reverse(p, q, k);
      // }
      return head;
    }
};
int main() {
  ListNode n1(1), n2(2), n3(3), n4(4), n5(5);
  n1.next = &n2;
  n2.next = &n3;
  n3.next = &n4;
  n4.next = &n5;
  Solution sol;
  ListNode *head = &n1;
  sol.reverseKGroup(&n1, 2);
  ListNode *p = head;
  while (p) {
    cout << p->val << " ";
    p = p->next;
  }
}
