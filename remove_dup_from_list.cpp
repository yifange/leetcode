#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
      if (!head || !head->next)
        return head;
      ListNode *p = head, *q = head->next;
      ListNode *prev = head;
      while (q) {
        if (p->val != q->val) {
          p = q;
          prev = prev->next;
          q = q->next;
        } else {
          prev->next = q->next;
          delete q;
          q = prev->next;
        }
      }
      return head;
    }
};

int main() {
  Solution sol;
  ListNode *a1 = new ListNode(1), *a2 = new ListNode(1), *a3 = new ListNode(2), *a4 = new ListNode(2), *a5 = new ListNode(3);
  a1->next = a2;
  a2->next = a3;
  a3->next = a4;
  a4->next = a5;
  sol.deleteDuplicates(a1);
  ListNode *head = a1;
  while (head) {
    cout << head->val << endl;
    head = head->next;
  }
}
