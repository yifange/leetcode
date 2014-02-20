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

