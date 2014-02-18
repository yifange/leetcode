#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
      int m = matrix.size();
      if (!m)
        return 0;
      int n = matrix.front().size();
      if (!m || !n)
        return 0;
      vector<vector<int> > h(m + 1, vector<int>(n, 0));
      vector<vector<int> > l(m + 1, vector<int>(n, 0));
      vector<vector<int> > r(m + 1, vector<int>(n, 0));
      for (int i = 0; i < n; i++)
        r[0][i] = n;
      for (int i = 1; i < m + 1; i++) {
        for (int j = 0; j < n; j++) {
          if (matrix[i - 1][j] == '0') {
            h[i][j] = 0;
            l[i][j] = 0;
            r[i][j] = n;
          } else {
            h[i][j] = h[i - 1][j] + 1;
            int k = j;
            while (k >= 0 && matrix[i - 1][k] == '1')
              k--;
            l[i][j] = (l[i - 1][j] > (k + 1)) ? l[i - 1][j] : (k + 1);
            k = j;
            while (k < n && matrix[i - 1][k] == '1')
              k++;
            r[i][j] = (r[i - 1][j] < (k - 1) ? r[i - 1][j] : (k - 1));
          }

        }
      }
      int max = 0;
      // for (int i = 1; i < m + 1; i++) {
      //   for (int j = 0; j < n; j++)
      //     cout << h[i][j] << " ";
      //   cout << endl;
      // }

      // for (int i = 1; i < m + 1; i++) {
      //   for (int j = 0; j < n; j++)
      //     cout << l[i][j] << " ";
      //   cout << endl;
      // }

      // for (int i = 1; i < m + 1; i++) {
      //   for (int j = 0; j < n; j++)
      //     cout << r[i][j] << " ";
      //   cout << endl;
      // }

      for (int i = 1; i < m + 1; i++) {
        for (int j = 0; j < n; j++) {
          if (h[i][j] * (r[i][j] - l[i][j] + 1) > max)
            max = h[i][j] * (r[i][j] - l[i][j] + 1);
        }
      }
      return max;
    }
};

int main() {
  vector<char> row1 {'1', '1'};
  vector<char> row2 {'0', '1'};
  vector<vector<char> > mat {};
  Solution sol;
  cout << sol.maximalRectangle(mat);
}
