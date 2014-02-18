#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
      vector<vector<int> > result (n, vector<int>(n));
      int left = 0, right = n, top = 0, bottom = n;
      int k = 1;
      while (k <= n * n) {
        if (left == right - 1 && top == bottom - 1) {
          result[top][left] = k++;
        }
        for (int i = left; i < right - 1; i++) {
          result[top][i] = k++;
        }
        for (int i = top; i < bottom - 1; i++) {
          result[i][right - 1] = k++;
        }
        for (int i = right - 1; i >= left + 1; i--) {
          result[bottom - 1][i] = k++;
        }
        for (int i = bottom - 1; i >= top + 1; i--) {
          result[i][left] = k++;
        }
        left++;
        top++;
        right--;
        bottom--;
      }
      return result;
    }

};
int main() {
    Solution sol;
    vector<vector<int> > result = sol.generateMatrix(8);
    for (int i = 0; i <8; i++) {
      for (int j =0; j < 8; j++) 
        cout << result[i][j] << " ";
      cout << endl;
    }
}
