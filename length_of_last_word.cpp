#include <iostream>
#include <cstring>
using namespace std;
class Solution {
  public:
    int lengthOfLastWord(const char *s) {
      int i = strlen(s) - 1;
      while (s[i] == ' ')
        i--;
      int l = 0;
      while (s[i] != ' ' && i >= 0) {
        l++;
        i--;
      }
      return l;
    }
};

int main() {
  Solution sol;
  cout << sol.lengthOfLastWord("world   ");
}
