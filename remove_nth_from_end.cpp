#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
      ListNode *probe = head, *current = head, *prev = NULL;        
      while (n > 0) {
        probe = probe->next;
        n--;
      }
      while (probe) {
        probe = probe->next;
        prev = current;
        current = current->next;
      }
      if (prev) {
        prev->next = current->next;
        // delete current;
        current = prev->next;
      } else {
        head = current->next;
        current = current->next;
      }
      return head;
    }
};
int main() {
  Solution sol;
  ListNode n1(1), n2(2), n3(3), n4(4), n5(5);
  n1.next = &n2;
  // n2.next = &n3;
  // n3.next = &n4;
  // n4.next = &n5;
  ListNode *head = sol.removeNthFromEnd(&n1, 1);
  while (head) {
    cout << head->val << endl;
    head = head->next;
  }
}
