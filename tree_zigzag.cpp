#include <vector>
#include <queue>
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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
      vector<queue<TreeNode *> > nodes (2);
      int i = 0;
      TreeNode *p; 
      vector<vector<int> > result;
      if (root) {
        nodes[i].push(root);
        do {
          vector<int>* level = new vector<int>();

          while (nodes[i].size()) {
            p = nodes[i].front();
            nodes[i].pop();
            if (i == 0)
              level->push_back(p->val);
            else
              level->insert(level->begin(), p->val);
            if (p->left)
              nodes[(i + 1) % 2].push(p->left);
            if (p->right)
              nodes[(i + 1) % 2].push(p->right);
          }
          i = (i + 1) % 2;
          result.push_back(*level);
        } while (nodes[i].size());
      }

      return result;
    }
};

int main() {
  TreeNode n4 (4);
  TreeNode n5 (5);
  TreeNode n3 (3);
  TreeNode n2 (2);
  TreeNode n1 (1);
  n1.left = &n2;
  n1.right = &n3;
  n3.left = &n4;
  n3.right = &n5;
  Solution sol;
  vector<vector<int> > result;
  result = sol.zigzagLevelOrder(NULL);
  for (int i = 0; i < result.size(); i++) {
    cout << "[";
    for (int j = 0; j < result[i].size(); j++) 
      cout << result[i][j];
    cout << "]";
  }
}
