#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int> &prices) {
      vector<int> diffs;
      if (prices.size() <= 1)
        return 0;
      if (prices.size() == 2) {
        if (prices[1] - prices[0] > 0)
          return prices[1] - prices[0];
        else
          return 0;
      }
      for (int i = 1; i < prices.size(); i++)
        diffs.push_back(prices[i] - prices[i - 1]);
      int sum = 0;
      int max_end_here = 0;
      int max1 = 0;
      vector<int> diffMax1;
      for (int i = 0; i < diffs.size(); i++) {
        if (max_end_here >= 0)
          max_end_here += diffs[i];
        else
          max_end_here = diffs[i];
        if (max_end_here > max1)
          max1 = max_end_here;
        diffMax1.push_back(max1);
      }
      max_end_here = diffs[0] + diffs[1];
      int max2 = max_end_here;
      for (int i = 2; i < diffs.size(); i++) {
        if (max_end_here > diffMax1[i - 1])
          max_end_here += diffs[i];
        else
          max_end_here = diffMax1[i - 1] + diffs[i];
        if (max_end_here > max2)
          max2 = max_end_here;
      }
      return (max1 > max2) ? max1 : max2;
              
    }
};
int main() {
  Solution sol;
  vector<int> prices {1, 4, 2};
  cout << endl << sol.maxProfit(prices);
}
