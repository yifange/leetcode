#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int> &prices) {
      vector<int> diffs;
      for (int i = 1; i < prices.size(); i++)
        diffs.push_back(prices[i] - prices[i - 1]);
      int max = 0;
      for (int i = 0; i < diffs.size(); i++) {
        if (diffs[i] > 0)
          max += diffs[i];
      }
      return max;
    }
};
int main() {
  Solution sol;
  vector<int> prices {1, 2, 1, 4, 5, 6};
  cout << sol.maxProfit(prices);
}
