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
    void getSum(TreeNode *root, int pathSum, int &sum) {
      if (!root)
        return;
      if (!root->left && !root->right)
        sum += pathSum * 10 + root->val;
      else {
        if (root->left)
          getSum(root->left, pathSum * 10 + root->val, sum);
        if (root->right)
          getSum(root->right, pathSum * 10 + root->val, sum);
      } 
    }
    int sumNumbers(TreeNode *root) {
      int sum = 0;
      getSum(root, 0, sum);
      return sum;
    }
};

int main() {
  TreeNode n1(1), n2(2), n3(3), n4(4);
  n1.left = &n2;
  // n1.right = &n3;
  Solution sol;
  cout << sol.sumNumbers(NULL) << endl;
}
