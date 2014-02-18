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
    TreeNode* tree(int l, int r, vector<TreeNode *> &result) {
      if (l - 1 == r) 
        return NULL;
      if (l == r)
        return new TreeNode(l);
      for (int i = l - 1; i < r; i++) {
        cout << i << endl;
        TreeNode *h1 = tree(l, i, result);
        TreeNode *h2 = tree(i + 1, r - 1, result);
        TreeNode *p = h1;
        cout << l << ":" << r << endl;
        if (h1) {
          // cout << "hello" << endl;
          while (p->right)
            p = p->right;
          TreeNode *cur = new TreeNode(r);
          p->right = cur;
          cur->left = h2;
          // cout << l << ":" << r << endl;
          result.push_back(h1);
        } else {
          // cout << "yoyo" << endl;
          TreeNode *cur = new TreeNode(r);
          cur->left = h2;
          // cout << l << ":" << r << endl;
          result.push_back(cur);
        }
      } 
      return NULL;
    }
    vector<TreeNode *> generateTrees(int n) {
      vector<TreeNode *> result;
      tree(1, n, result);
      return result;
    }
};

int main() {
  Solution sol;
  cout << sol.generateTrees(3).size();
}
