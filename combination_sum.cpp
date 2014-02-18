#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    void search(vector<int> candidates, int target, vector<int> current, vector<vector<int> > &answer) {
      vector<int>::iterator it;
      if (target == 0) {

        vector<int> newAnswer(current);
        answer.push_back(newAnswer);
        return;
      }
      if (candidates.size())
        for (it = candidates.begin(); it != candidates.end(); ++it) {
          // cout << "current: ";
          // for (int i = 0; i < current.size(); i++)
          //   cout << current[i] << " ";
          // cout << endl;
          // cout << "try: " << *it << endl;
          if (*it <= target) {
            // cout << "Picking: " << *it << endl;
            current.push_back(*it);
            search(vector<int>(it, candidates.end()), target - *it, current, answer);
            current.pop_back();

          }
        }
    }

    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
      vector<vector<int> > answer;
      vector<int> current;
      vector<int> candidatesCopy(candidates);
      for (int i = 0; i < candidates.size() - 1; i++)
        for (int j = i + 1; j < candidates.size(); j++) {
          if (candidatesCopy[i] > candidatesCopy[j]) {
            int t = candidatesCopy[i];
            candidatesCopy[i] = candidatesCopy[j];
            candidatesCopy[j] = t;
          }
        }
      search(candidatesCopy, target, current, answer);
      return answer;
    }
};

int main() {
  Solution sol;
  vector<int> candidates {8, 7, 4, 3};
  vector<vector<int> > result;
  result = sol.combinationSum(candidates, 11);
  for (int i = 0; i < result.size(); i++) {
    for (int j = 0; j < result[i].size(); j++)
      cout << result[i][j] << " ";
    cout << endl;
  }
}
