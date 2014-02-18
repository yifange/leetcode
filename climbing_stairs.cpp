#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  int solve(int n, vector<int> &cache) {
    if (n < 0)
      return 0;
    if (cache[n])
      return cache[n];
    else {
      cache[n] = solve(n - 1, cache) + solve(n - 2, cache);
      return cache[n];
    }
  }
    int climbStairs(int n) {
      vector<int> cache(n + 1, 0);
      cache[0] = 1;
      return solve(n, cache);
    }
};
int main() {
  Solution sol;
  cout << sol.climbStairs(4);
}
