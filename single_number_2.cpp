#include <iostream>
using namespace std;
class Solution {
public:
    int singleNumber(int A[], int n) {
      int ones = 0, twos = 0, threes = 0;        
      for (int i = 0; i < n; i++) {
        twos |= ones & A[i];
        ones ^= A[i];
        threes = ones & twos;
        ones &= ~threes;
        twos &= ~threes;
      }
      return ones;
    }
};
int main() {
  int a[] = {1, 1, 1, 2, 2, 2, 3, 3, 3, 9};
  Solution sol;
  cout << sol.singleNumber(a, 10);
}
