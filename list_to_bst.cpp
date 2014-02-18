#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  public:
    TreeNode *convert(ListNode **head, int start, int end) {
      if (end < start)
        return NULL;
      int mid = (start + end) / 2;
      TreeNode *leftRoot = convert(head, start, mid - 1);
      TreeNode *root = new TreeNode((*head)->val);
      *head = (*head)->next;
      root->left = leftRoot;
      root->right = convert(head, mid + 1, end);
      return root;
    }
    TreeNode *sortedListToBST(ListNode *head) {
      int n = 0;
      ListNode *p = head;
      while (p) {
        n++;
        p = p->next;
      }
      TreeNode *root = convert(&head, 1, n); 
      return root;
    }
};
void traverse(TreeNode *root) {
  if (root->left)
    traverse(root->left);
  cout << root->val;
  if (root->right)
    traverse(root->right);

}
int main() {
  ListNode n1(1), n2(2), n3(3), n4(4), n5(5), n6(6), n7(7);
  n1.next = &n2;
  n2.next = &n3; 
  n3.next = &n4;
  n4.next = &n5;
  n5.next = &n6;
  // n6.next = &n7;

  Solution sol;
  TreeNode *root = sol.sortedListToBST(&n1);
  traverse(root);
}
