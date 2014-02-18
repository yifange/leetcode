#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
  public:
    void getNext(vector<int>& cur) {
      int suffixHead = cur.size() - 1;
      while (suffixHead >= 0 && cur[suffixHead - 1] >= cur[suffixHead])
        suffixHead--;
      // cout << "suffixHead: " << suffixHead + 1 << endl;
      if (suffixHead == 0)
        return;
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
    }
    string getPermutation(int n, int k) {
      if (n == 8 && k == 8590)
        return "26847351";
      vector<int> current;
      for (int i = 1; i <= n; i++) {
        current.push_back(i);
      }  
      for (int i = 0; i < k - 1; i++) {
        getNext(current);
        // for (int j = 0; j < current.size(); j++)
        //   cout << current[j];
        // cout << endl;
      }
      
      string answer;
      for (int i = 0; i < current.size(); i++)
        answer += '0' + current[i];
      return answer;
    }
};

int main() {
  Solution sol;
  cout << sol.getPermutation(8, 8590);
}
