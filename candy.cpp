#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int candy(vector<int> &ratings) {
      vector<int> candies;
      int current = 1;
      int sum = 0;
      int lastInd = 0;
      int lastMax = 0;
      int i = 0;
      while (i < ratings.size()) {
        while (i < ratings.size() - 1 && ratings[i + 1] > ratings[i]) {
          sum += current;
          current++;
          i++;
        }
        if (i == ratings.size() - 1) {
          sum += current; 
          break;
        }
        while (i < ratings.size() - 1 && ratings[i + 1] == ratings[i]) {
          current = 1;
          sum += 1;
          i++;
        }
        if (ratings[i - 1] == ratings[i]) {
          sum += 1;
          // i++;
        }

        sum += current;
        lastMax = current;
        current = 1;
        lastInd = i;
        if (i >= ratings.size())
          break;
        i++;
        while (i < ratings.size() && ratings[i] < ratings[i - 1]) {
          i++;
        }
        int diff = i - lastInd - 1;
        cout << lastInd << endl;
        cout << i << endl;
        cout << diff;
        sum += (1 + diff) * diff / 2;
        if (diff > lastMax)
          sum += diff - lastMax;
        current++;
        lastMax = 0;
        lastInd = 0;
      }
      return sum;
    }
};

int main() {
  Solution sol;
  vector<int> ratings {2, 2, 2};
  cout << sol.candy(ratings);
}
