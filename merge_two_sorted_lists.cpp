#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
      ListNode *p;
      ListNode *head;
      bool is_head = true;
      if (!l1 && !l2)
        return NULL;
      else if (l1 && l2)
        if (l1->val < l2->val) {
          p = new ListNode(l1->val);
          l1 = l1->next;
        } else {
          p = new ListNode(l2->val);
          l2 = l2->next;
        }
      else if (l1) {
        p = new ListNode(l1->val);
        l1 = l1->next;
      } else {
        p = new ListNode(l2->val);
        l2 = l2->next;
      }
      head = p;
      while (l1 && l2) {
        if (l1->val < l2->val) {
          p->next = new ListNode(l1->val);
          l1 = l1->next;
        } else {
          p->next = new ListNode(l2->val);
          l2 = l2->next;
        }
        p = p->next;
      }
      while (l1) {
        p->next = new ListNode(l1->val);
        p = p->next;
        l1 = l1->next;
      }
      while (l2) {
        p->next = new ListNode(l2->val);
        p = p->next;
        l2 = l2->next;
      }
      return head;
    }
};
int main() {
  ListNode n1(1), n3(3), n5(5);
  ListNode m2(2), m4(4), m6(6);
  n1.next = &n3;
  n3.next = &n5;
  m2.next = &m4;
  m4.next = &m6;
  Solution sol;
  ListNode *head = sol.mergeTwoLists(&n1, &m2);
  while (head) {
    cout << head->val << endl;
    head = head->next;
  }
}
