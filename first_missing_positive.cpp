#include <iostream>
using namespace std;

class Solution {
public:
    int firstMissingPositive(int A[], int n) {
      int a[n];
      for (int i = 0; i < n; i++) {
        a[i] = A[i];
      }
      int j = 0;
      for (int i = 0; i < n; i++) {
        if (a[i] > 0) {
          int t = a[i];
          a[i] = a[j];
          a[j] = t;
          j++;
        }
      }
      // for (int i = 0; i < n; i++) {
      //   cout << a[i] << " ";
      // }
      // cout << endl << j << endl;
      for (int i = 0; i < j; i++) {
        // cout << "for: " << a[i] << endl;
        if (abs(a[i]) <= j) {
          if (a[abs(a[i]) - 1] > 0) {
            a[abs(a[i]) - 1] = -a[abs(a[i]) - 1];
          }
        }
      }
      // for (int i = 0; i < n; i++) {
      //   cout << a[i] << " ";
      // }
      // cout << endl;
      for (int i = 0; i < j; i++) 
        if (a[i] > 0)
          return i + 1;
      return j + 1;
    }
};

int main() {
  int A[] = {1, 3, 4};
  Solution sol;
  cout << endl << sol.firstMissingPositive(A, 3);

}
