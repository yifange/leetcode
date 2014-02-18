#include <iostream>
using namespace std;

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
      int i = 0;
      while (i < n) {
        while (A[n - 1] == elem && i < n)
          n--;
        while (A[i] != elem && i < n)
          i++;
        if (i < n) {
          cout << "left: " << A[i] << "right: " << A[n - 1] << endl;
          int temp = A[i];
          A[i] = A[n - 1];
          A[n - 1] = temp;
          // n--;
          // i++;
        }
          
      }  
      while (A[n - 1] == elem && n > 1)
        n--;
      return n;
    }
};
int main() {
  Solution sol;
  int a[] = {2, 2, 2};
  int n;
  n = sol.removeElement(a, 3, 2);
  cout << n << endl;
  for (int i = 0; i < n; i++)
    cout << a[i] << " ";
  cout << endl;
}
