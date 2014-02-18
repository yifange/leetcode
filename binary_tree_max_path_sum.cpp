#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
const int MIN_INT = -32767;
struct TreeSumNode {
  int val;
  int left_max;
  int right_max;
  TreeSumNode *left;
  TreeSumNode *right;
  TreeSumNode(): val(0), left_max(MIN_INT), right_max(MIN_INT), left(NULL), right(NULL) {};
  // TreeSumNode(int x, int left_m, int right_m, TreeSumNode *l, TreeSumNode *r): val(x), left_max(0), right_max(0), left(NULL), right(NULL) {}
};
class Solution {
public:
  void copyNodes(TreeNode *root, TreeSumNode *sumRoot) {
    sumRoot->val = root->val;
    if (root->left) {
      TreeSumNode *newNode = new TreeSumNode();
      sumRoot->left = newNode;
      copyNodes(root->left, newNode);
    }
    if (root->right) {
      TreeSumNode *newNode = new TreeSumNode();
      sumRoot->right = newNode;
      copyNodes(root->right, newNode);
    }
  }
  TreeSumNode* copyTree(TreeNode *root) {
    if (root) {
      TreeSumNode *sumRoot = new TreeSumNode();
      copyNodes(root, sumRoot);
      return sumRoot;
    } else {
      return NULL;
    }
  }
  int getMax(TreeSumNode *node) {
    if (!node)
      return 0;
    else {
      if (node->left_max == MIN_INT)
        node->left_max = getMax(node->left);
      if (node->right_max == MIN_INT)
        node->right_max = getMax(node->right);
      if (node->left_max > node->right_max)
        if (node->left_max + node->val > 0)
          return node->val + node->left_max;
        else
          return 0;
      else
        if (node->right_max + node->val > 0)
          return node->val + node->right_max;
        else
          return 0;

    }
  }
  void traverse(TreeSumNode *node, int &max) {
    int sum = node->val + node->left_max + node->right_max;
    if (sum > max)
      max = sum;
    if (node->left)
      traverse(node->left, max);
    if (node->right)
      traverse(node->right, max);
  }
  int maxPathSum(TreeNode *root) {
    TreeSumNode *sumRoot = copyTree(root);         
    getMax(sumRoot); 
    int max = MIN_INT;
    traverse(sumRoot, max);
    return max;  
  }
};

int main() {
  Solution sol;
  TreeNode n1(-2), n2(1), n3(3), n4(4), n5(5), n6(6);
  // n1.left = &n2;
  // n1.right = &n3;
  // n2.left = &n6;
  // n2.right = &n5;
  // n3.right = &n4;
  cout << sol.maxPathSum(&n1) << endl;
}
