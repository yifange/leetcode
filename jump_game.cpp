#include <iostream>
using namespace std;

class Solution {
public:

    bool canJump(int A[], int n) {
      if (!n) {
        return false;
      }
      bool d[n];
      d[0] = true;
      for (int i = 0; i < n - 1; i++) {
        if (d[i]) {
          for (int j = 0; j <= A[i]; j++) {
            if (i + j < n)
              d[i + j] = true;
            else
              return true;
          }
        }
      }
      return d[n - 1];
    }
};
int main() {
  int A[5] = {3, 2, 1, 0, 4};
  Solution sol;
  cout << sol.canJump(A, 5);
}
