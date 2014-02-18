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
    void flatten(TreeNode *root) {
      if (!root)
        return;
      flatten(root->left);
      flatten(root->right);
      TreeNode *p = root->left;
      if (p) {
        while (p->right) {
          p = p->right;
        }
        p->right = root->right;
        root->right = root->left;
        root->left = NULL;
      }
    }
};

int main() {
  TreeNode n1(1), n2(2), n3(3), n4(4), n5(5), n6(6);
  // n1.left = &n2;
  n1.right = &n5;
  // n2.left = &n3;
  // n2.right = &n4;
  // n5.right = &n6;
  Solution sol;
  sol.flatten(&n1);
  TreeNode *p = &n1;
  while (p) {
    cout << p->val << endl;
    p = p->right;
  }
}
