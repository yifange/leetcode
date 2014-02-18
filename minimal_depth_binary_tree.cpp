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
    int minDepth(TreeNode *root) {
      if (!root)
        return 0;
      if (!root->left && !root->right)
        return 1;
      else if (root->left && !root->right)
        return minDepth(root->left) + 1;
      else if (root->right && !root->left)
        return minDepth(root->right) + 1;
      else {
        int left = minDepth(root->left);
        int right = minDepth(root->right);
        return (left < right) ? (left + 1) : (right + 1);
      }
    }
};

int main() {
  TreeNode n1(1), n2(2), n3(3);
  // n1.left = &n2;
  // n2.left = &n3;
  Solution sol;
  cout << sol.minDepth(&n1);
}
