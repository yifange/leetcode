#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool binarySearch(vector<vector<int> > &matrix, int target, int left, int right, int n) {
      int mid = (left + right) / 2;
      int mm = mid / n;
      int nn = mid % n;
      
      if (left < right)
        if (matrix[mm][nn] == target)
          return true;
        else
          return binarySearch(matrix, target, left, mid, n) || binarySearch(matrix, target, mid + 1, right, n);
      else
        return false;
    }
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
      int m = matrix.size();
      int n = matrix[0].size();
      return binarySearch(matrix, target, 0, m * n, n);
    }
};

int main() {
  Solution sol;
  vector<int> row1 {1,   3,  5,  7};
  vector<int> row2 {10, 11, 16, 20};
  vector<int> row3 {23, 30, 34, 50};
  vector<vector<int> > matrix {row1, row2, row3};
  cout << sol.searchMatrix(matrix, 1) << endl;
}
