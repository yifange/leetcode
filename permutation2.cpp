#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> getNext(vector<int> prev, bool &finished) {
      vector<int> cur(prev);
      int suffixHead = cur.size() - 1;
      while (suffixHead >= 0 && cur[suffixHead - 1] >= cur[suffixHead])
        suffixHead--;
      // cout << "suffixHead: " << suffixHead + 1 << endl;
      if (suffixHead == 0) {
        finished = true;
        return cur;
      }
      int pivot = suffixHead - 1;
      int candidateInd = cur.size() - 1;
      while (cur[candidateInd] <= cur[pivot])
        candidateInd--;
      // cout << "candidateInd" << candidateInd + 1 << endl;
      cur[candidateInd] ^= cur[pivot];
      cur[pivot] ^= cur[candidateInd];
      cur[candidateInd] ^= cur[pivot];
      for (int i = suffixHead; i < (cur.size() + suffixHead) / 2; i++) {
        int j = cur.size() - 1 + suffixHead - i;
        // cout << "swap: " << i + 1 << " and " << j + 1 << endl;
        cur[i] ^= cur[j];
        cur[j] ^= cur[i];
        cur[i] ^= cur[j];
      }
      finished = false;
      return cur;
    }
    vector<vector<int> > permute(vector<int> &num) {
      vector<vector<int> > result;
      vector<int> n(num);
      for (int i = 0; i < n.size() - 1; i++)
        for (int j = i + 1; j < n.size(); j++) {
          if (n[i] > n[j]) {
            n[i] ^= n[j];
            n[j] ^= n[i];
            n[i] ^= n[j];
          }
        }
      result.push_back(n);
      bool finished = false;
      vector<int> cur;
      while (!finished) {
        cur = getNext(result.back(), finished);
        if (!finished)
          result.push_back(cur);
      }
      return result;
    }
};

int main() {
  Solution sol;
  vector<int> num {1};
  vector<vector<int> > result = sol.permute(num);
  for (int i = 0; i < result.size(); i++) {
    cout << "[ ";
    for (int j = 0; j < result[i].size(); j++) 
      cout << result[i][j];
    cout << " ]" << endl;
  }
}
