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
  bool isMirror(TreeNode *leftRoot, TreeNode *rightRoot) {
    if (!leftRoot && !rightRoot)
      return true;
    else if (leftRoot && rightRoot && leftRoot->val == rightRoot->val)
      return isMirror(leftRoot->left, rightRoot->right) && isMirror(leftRoot->right, rightRoot->left);
    else
      return false;
  }
  bool isSymmetric(TreeNode *root) {
    if (!root)
      return true;
    return isMirror(root->left, root->right);
  }
};

int main() {
  TreeNode n1(1), n21(2), n22(2), n31(3), n32(3), n41(4), n42(4);

  n1.left = &n21;
  // n1.right = &n22;
  // n21.left = &n31;
  // n21.right = &n41;
  // n22.left = &n42;
  // n22.right = &n32;
  Solution sol;
  cout << sol.isSymmetric(&n1);
}
