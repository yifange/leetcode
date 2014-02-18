#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
      vector<int> r;
      r.push_back(1);
      for (int k = 1; k <= n; k++) {
        int sum = 0;
        for (int i = 1; i <= k; i++) {
          sum += r[k - i] * r[i - 1];
        }
        r.push_back(sum);
      }
      
      return r[n];
    }
};
int main() {
  Solution sol;
  cout << sol.numTrees(3);
}
