#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int> &prices) {
      if (prices.size() == 0)
        return 0;
      int partialMin = prices[0];
      int maxDiff = 0;
      for (int i = 1; i < prices.size(); i++) {
        if (prices[i] < partialMin)
          partialMin = prices[i];
          if (prices[i] - partialMin > maxDiff)
            maxDiff = prices[i] - partialMin;
      }
      return maxDiff;
    }
};
int main() {
  Solution sol;
  vector<int> prices {};
  cout << sol.maxProfit(prices);
}
