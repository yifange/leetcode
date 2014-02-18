#include <iostream>
using namespace std;
class Solution {
public:
    int sorted_search(int a[], int left, int right, int target) {
      // cout << "sorted: left: " << left << "right: " << right << endl;
      int m = (left + right) / 2;
      if (left >= right) 
        return -1;
      if (a[m] == target) {
        // cout << "found: " << m << endl;
        return m;

      }
      int left_result = sorted_search(a, left, m, target);
      if (sorted_search(a, left, m, target) != -1)
        return left_result;
      int right_result = sorted_search(a, m + 1, right, target);
      if (right_result != -1)
        return right_result;
      return -1;

    }
    int rotated_search(int a[], int left, int right, int target) {
        // cout << "rotated: left: " << left << "right: " << right << endl;
        int m = (left + right) / 2;
        if (left >= right)
          return -1;
        if (a[m] == target)
          return m;


        int left_result = -1;
        int right_result = -1;
        if (a[left] < a[m]) {
          int left_result = sorted_search(a, left, m, target);
          if (left_result != -1)
            return left_result;
          int right_result = rotated_search(a, m + 1, right, target);
          if (right_result != -1)
            return right_result;

        } else {
          int left_result = rotated_search(a, left, m, target);
          if (left_result != -1)
            return left_result;
          int right_result = sorted_search(a, m + 1, right, target);
          if (right_result != -1)
            return right_result;
        }
        return -1;
    }
    int search(int A[], int n, int target) {
        return rotated_search(A, 0, n, target);  
    }
};

int main() {
  int a[] = {1};
  Solution sol;
  cout << sol.search(a, 1, 0);
}
