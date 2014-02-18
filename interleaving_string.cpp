#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
  public:
    bool isInterleave(string s1, string s2, string s3) {
      int m = s1.length();
      int n = s2.length();
      if (m + n != s3.length())
        return false;
      vector<vector<bool> > mat (m + 1, vector<bool>(n + 1, 0));
      
      mat[0][0] = true;
      for (int sum = 1; sum <= m + n; sum++) 
        for (int i = 0; i <= m; i++) {
          int j = sum - i;
          if (j >= 0 && j <= n) {
            if (i > 0 && mat[i - 1][j] && s3[i + j - 1] == s1[i - 1])
              mat[i][j] = true;
            else if (j > 0 && mat[i][j - 1] && s3[i + j - 1] == s2[j - 1])
              mat[i][j] = true;
            else 
              mat[i][j] = false;
          }
        }

      // for (int i = 0; i <= m; i++) {
      //   for (int j = 0; j <= n; j++)
      //     cout << mat[i][j] << " ";
      //   cout << endl;
      // }
      return mat[m][n];
    }
};

int main() {
  string s1 = "";
  string s2 = "";
  string s3 = "a";
  Solution sol;
  cout << sol.isInterleave(s1, s2, s3);
}
