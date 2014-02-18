#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
      vector<vector<int> > f;
      f.push_back(triangle[0]);
      for (int i = 1; i < triangle.size(); i++) {
        vector<int> row;
        for (int j = 0; j < i + 1; j++) {
          int left = (j >= 1) ? f[i - 1][j - 1] : 65000;
          int right = (j < i) ? f[i - 1][j] : 65000;
          if (left < right)
            row.push_back(left + triangle[i][j]);
          else
            row.push_back(right + triangle[i][j]);
        }
        f.push_back(row);
      }
      int min = 65535;
      vector<int> lastRow = f.back();
      // for (int i = 0; i < f.size(); i++) {
      //   for (int j = 0; j < f[i].size(); j++) 
      //     cout << f[i][j] << " ";
      //   cout << endl;
      // }

      for (int i = 0; i < lastRow.size(); i++) {
        if (lastRow[i] < min)
          min = lastRow[i];
      }
      return min;
    }
};
int main() {
  vector<int> row1 {2};
  vector<int> row2 {3, 4};
  vector<int> row3 {6, 5, 7};
  vector<int> row4 {4, 1 ,8, 3};
  vector<vector<int> > tri {row1, row2, row3, row4};
  Solution sol;
  cout << sol.minimumTotal(tri);
}
