#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    bool hasCycle(ListNode *head) {
      ListNode *p = head;
      ListNode *q = head; 
      while (p && q) {
        p = p->next;
        q = q->next;
        if (q) {
          q = q->next;
        } else {
          return false;
        }
        if (p == q)
          return true;
      }
      return false;
    }
};

int main() {
  ListNode p (1);
  Solution sol;
  bool result;
  result = sol.hasCycle(&p);
  cout << result;
}
