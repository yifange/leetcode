#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
      int left = 0, right = s.length() - 1;        
      while (left < right) {
        while (!isalnum(s[left]) && left < s.length()) 
          left++;
        while (!isalnum(s[right]) && right > 0) 
          right--;
        if (left >= right)
          break;
        if (tolower(s[left]) == tolower(s[right])) {
          left++;
          right--;
        } else {
          return false;
        }
      }
      return true;
    }
};

int main () {
  string s (".,");
  Solution sol;
  cout << sol.isPalindrome(s);
}
