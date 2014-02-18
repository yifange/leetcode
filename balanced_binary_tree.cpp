#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    bool isBalanced(TreeNode *root) {
      if (!root)
        return true;
      if (!root->left && !root->right) {
        root->val = 1;
        return true;
      }
      else if (!root->left && root->right) {
        bool ok = isBalanced(root->right);
        root->val = root->right->val + 1;
        return ok && (root->val <= 2);
      }
      else if (!root->right && root->left) {
        bool ok = isBalanced(root->left);
        root->val = root->left->val + 1;
        return ok && (root->val <= 2);
      }
      // if (root->left && root->right)
      else {
        bool ok = isBalanced(root->left) && isBalanced(root->right);
        int val = root->left->val;
        if (root->right->val > val)
          val = root->right->val;
        root->val = val + 1;
        return ok && (abs(root->left->val - root->right->val) <= 1);
      }
    }
};

int main() {
  TreeNode n1(0), n2(0), n3(0), n4(0);
  // n1.left = &n2;
  // n1.right = &n3;
  // n2.left = &n4;
  Solution sol;
  cout << sol.isBalanced(NULL);
}
