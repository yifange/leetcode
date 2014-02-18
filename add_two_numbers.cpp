#include <iostream>
#include <vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
      int carry = 0;
      ListNode *head = new ListNode(0);
      ListNode *p = head;
      while (l1 && l2) {
        int sum = carry + l1->val + l2->val;
        if (sum > 9) {
          sum -= 10;
          carry = 1;
        } else 
          carry = 0;
        ListNode *q = new ListNode(sum);
        p->next = q;
        p = q;
        l1 = l1->next;
        l2 = l2->next;
      }
      while (l1) {
        int sum = l1->val + carry;
        if (sum > 9) {
          sum -= 10;
          carry = 1;
        } else {
          carry = 0;
        }
        ListNode *q = new ListNode(sum);
        p->next = q;
        p = q;
        l1 = l1->next;
      }
      while (l2) {
        int sum = l2->val + carry;
        if (sum > 9) {
          sum -= 10;
          carry = 1;
        } else {
          carry = 0;
        }
        ListNode *q = new ListNode(sum);
        p->next = q;
        p = q;
        l2 = l2->next;
      }
      if (carry) {
        ListNode *q = new ListNode(carry);
        p->next = q;
        carry = 0;
      }
      p = head->next;
      delete head;
      return p;
    }
};
int main() {
  ListNode n1(1), n2(4), n3(3), n4(9), n5(9), n6(4);
  n1.next = &n2;
  // n2.next = &n3;
  n4.next = &n5;
  // n5.next = &n6;
  Solution sol;
  ListNode *p = sol.addTwoNumbers(&n1, &n4);
  while (p) {
    cout << p->val << " ";
    p = p->next;
  }

}
