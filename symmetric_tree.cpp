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
    bool isSymmetric(TreeNode *root) {
      vector<vector<TreeNode *> > queues (2, vector<TreeNode* >());
      int l = 0;
      int len = 1;
      if (!root)
        return true;
      queues[0].push_back(root);
      while (1) {
        queues[(l + 1) % 2].clear();
        // cout << "length: " << queues[l].size() << endl;
        // cout << "l: " << l << endl;
        for (int i = 0; i < len; i++) {
          if (queues[l][i]) {
            queues[(l + 1) % 2].push_back(queues[l][i]->left);
            queues[(l + 1) % 2].push_back(queues[l][i]->right);
          } else {
            queues[(l + 1) % 2].push_back(NULL);
            queues[(l + 1) % 2].push_back(NULL);
          }
        }
          // cout << endl;
        l = (l + 1) % 2;
        len *= 2;
        bool valid = true;
        bool hasNode = false;
        // for (int k = 0; k < len; k++) {
        //   if (queues[l][k])
        //     cout << queues[l][k]->val << " ";
        //   else
        //     cout << "NULL ";
        //   cout << endl;
        // }
        for (int k = 0; k < queues[l].size() / 2; k++) {
          int j = queues[l].size() - k - 1;
          if (!queues[l][k] && !queues[l][j])
            continue;
          else if (queues[l][k] && queues[l][j] && queues[l][k]->val == queues[l][j]->val) {
            hasNode = true;
            continue;
          } else {
            valid = false;
            break;
          }
        }
        if (!valid)
          return false;
        if (!hasNode)
          return true;
      }
      return true;
    }
};

int main() {
  TreeNode n1(1), n21(2), n22(2), n31(3), n32(3), n41(4), n42(4);
  // n1.left = &n21;
  // n1.right = &n22;
  // n21.left = &n31;
  // n21.right = &n41;
  // n22.left = &n42;
  // n22.right = &n32;
  Solution sol;
  cout << sol.isSymmetric(&n1);
}
