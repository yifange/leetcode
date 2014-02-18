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

private:
    vector<int> nodes;
public:
    void traverse(TreeNode *root) {
      if (root->left)
        traverse(root->left);
      this->nodes.push_back(root->val);
      if (root->right)
        traverse(root->right);
    }
    bool isValidBST(TreeNode *root) {
      if (!root)
        return true;
      traverse(root);
      bool ordered = true;
      for (int i = 0; i < this->nodes.size() - 1; i++) {
        if (nodes[i] >= nodes[i + 1])
          ordered = false;
      }
      return ordered;
    }
};
int main() {
  TreeNode n1(1);
  TreeNode n2(2);
  TreeNode n3(3);
  Solution sol;
  cout << sol.isValidBST(NULL);
}
