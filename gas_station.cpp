#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
       bool found = false; 
       int i = 0, j = 0;
       int sum = 0;
       int len = gas.size();
       int step = 0;
       while (step < len * 2) {
          sum += (gas[i] - cost[i]);
          // cout << gas[i] - cost[i] << endl;
          // cout << sum << endl;
          if (sum < 0) {
            sum = 0;
            i = (i + 1) % len;
            j = i;
            found = false;
          } else {
            i = (i + 1) % len;
            found = true;
          }
          step++;
       }
       // cout << "sum: " << sum << endl; 
       if (sum > 0 || (sum == 0 && found))
         return j;
       else
         return -1;
    }
};
int main() {
  vector<int> gas {2, 4};
  vector<int> cost {3, 4};
  Solution sol;
  cout << sol.canCompleteCircuit(gas, cost) << endl;
}
