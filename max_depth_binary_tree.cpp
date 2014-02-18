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
    int maxDepth(TreeNode *root) {
      if (!root)
        return 0;
      else {
        int d1 = maxDepth(root->left);
        int d2 = maxDepth(root->right);
        return (d1 > d2) ? (d1 + 1) : (d2 + 1);
      }
    }
};

int main() {
  Solution sol;
  TreeNode n1(1), n2(2), n3(3), n4(4), n5(5);
  n1.left = &n2;
  n1.right = &n3;
  n2.left = &n4;
  n3.right = &n5;
  cout << sol.maxDepth(&n1);
}
