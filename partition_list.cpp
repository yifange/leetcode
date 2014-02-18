#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// class Solution {
// public:
//     ListNode *partition(ListNode *head, int x) {
//       ListNode *p = head, *q = head;
//       while (q) {
//         if (q->val < x) {
//           int temp = p->val;
//           p->val = q->val;
//           q->val = temp;
//           p = p->next;
//         }
//         q = q->next;
//       }
//       return head;
//     }
// };
// 
class Solution {
  public:
    ListNode *partition(ListNode *head, int x) {
      ListNode *head1 = new ListNode(-1), *head2 = new ListNode(-1);
      ListNode *h1 = head1, *h2 = head2;
      ListNode *current = head;
      while (current) {
        if (current->val < x) {
          head1->next = current;
          head1 = head1->next;
        } else {
          head2->next = current;
          head2 = head2->next;
        }
        current = current->next;
      }
      head1->next = h2->next;
      head1 = h1->next;
      head2->next = NULL;
      delete h1;
      delete h2;
      return head1;
    }
};
int main() {
  ListNode n1(2), n2(3), n3(1), n4(2), n5(5), n6(2);
  n1.next = &n2;
  n2.next = &n3;
  // n3.next = &n4;
  // n4.next = &n5;
  // n5.next = &n6;
  Solution sol;
  ListNode *p = sol.partition(&n1, 2);
  // ListNode *p = &n1;
  while (p) {
    cout << p->val << " ";
    p = p->next;
  }

}
