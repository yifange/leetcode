#include <iostream>
using namespace std;
class Solution {
public:
    int singleNumber(int A[], int n) {
      int ans = 0;
      for (int i = 0; i < n; i++) {
        ans ^= A[i];
      }    
      return ans;
    }
};
int main() {
  int a[] = {1, 2, 3, 3, 1};
  Solution sol;
  cout << sol.singleNumber(a, 0);
}
