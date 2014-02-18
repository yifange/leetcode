#include <vector>
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    string sort_string(string &str) {
      string s = str;
      cout << "length" << s.length() << endl;
      for (int i = 0; i < s.length(); i++) {
        cout << "hello";
        for (int j = i + 1; j < s.length(); j++) 
          if (s[i] > s[j]) {
            char t = s[i];
            s[i] = s[j];
            s[j] = t;
          }
      }
      cout << "hello" << endl;
      cout << s << endl;
      return s;
    }
    vector<string> anagrams(vector<string> &strs) {
      vector<string> result;
      vector<string> normed_strs;
      for (int i = 0; i < strs.size(); i++) {
        normed_strs.push_back(sort_string(strs[i]));
      }
      cout << 1 << endl;
      for (int i = 0; i < strs.size() - 1; i++)
        for (int j = i + 1; j < strs.size(); j++) 
          if (normed_strs[i] > normed_strs[j]) {
            string t;
            t = normed_strs[i];
            normed_strs[i] = normed_strs[j];
            normed_strs[j] = t;
            t = strs[i];
            strs[i] = strs[j];
            strs[j] = t;
          }
      cout << 2 << endl;

      for (int i = 0; i < strs.size(); i++)
        cout << normed_strs[i] << " ";
      cout << endl;

      string t;
      int begin = 0;
      for (int i = 0; i < strs.size(); i++) {
        if (normed_strs[i] != t) {
          t = normed_strs[i];
          if (i - 1 > begin) {
            for (int j = begin; j < i; j++)
              result.push_back(strs[j]);
          }
          begin = i;
        }
      }
      return result; 
    }
};

int main() {
  Solution sol;
  vector<string> strs {""};
  vector<string> result = sol.anagrams(strs);
  for (int i = 0; i < result.size(); i++)
    cout << result[i] << " ";
}
