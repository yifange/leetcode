#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    void traverse(TreeNode *root, vector<int>& result) {
      if (root->left)
        traverse(root->left, result);
      result.push_back(root->val);
      if (root->right)
        traverse(root->right, result);
    }
    vector<int> inorderTraversal(TreeNode *root) {
      vector<int> result;
      if (root)
        traverse(root, result);
      return result;
    }
};
int main() {
  TreeNode n1(1), n2(2), n3(3), n4(4), n5(5), n6(6);
  n1.left = &n2;
  n1.right = &n3;
  n2.left = &n4;
  n2.right = &n5;
  n3.left = &n6;
  Solution sol;
  vector<int> result = sol.inorderTraversal(&n1);
  for (int i = 0; i < result.size(); i++)
    cout << result[i] << endl;
}
