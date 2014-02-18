#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        int m, n;
        m = matrix.size();
        n = matrix.front().size();
        vector<int> a (m * n);
        int i = 0, j = 0, k = 0;
        int left = 0, right = n, top = 0, bottom = m;
        while (k < m * n) {
            if (left == right - 1 && top == bottom - 1) {
              a[k] = matrix[top][left];
              k++;
            }
            for (int i = left; i < right - 1; i++) {
                // cout << "(" << top << "," << i << ")";
                a[k] = matrix[top][i];
                k++;
            }
            for (int i = top; i < bottom - 1; i++) {
                // cout << "(" << i << "," << right - 1 << ")";
                a[k] = matrix[i][right - 1];
                k++;
            }
            for (int i = right - 1; i >= left + 1; i--) {
                // cout << "(" << bottom - 1 << "," << i << ")";
                a[k] = matrix[bottom - 1][i];
                k++;
            }
            for (int i = bottom - 1; i >= top + 1; i--) {
                // cout << "(" << i << "," << left << ")";
                a[k] = matrix[i][left];
                k++;
            }
            left++;
            top++;
            right--;
            bottom--;
        }
        // cout << left << right << top << bottom;
        for (int i = 0; i < m * n; i++) 
            cout << a[i] << " ";
        return a;

    }
};

int main() {
    Solution sol;
    vector<int> row1 {1};
    vector<int> row2 {12};
    vector<int> row3 {11};
    vector<int> row4 {10, 9};

    vector <int> emp {};  
    vector<vector<int> > matrix {emp};
    // vector<vector<int>> matrix {row1, row2};
    sol.spiralOrder(matrix);
}
