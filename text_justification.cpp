#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
      int words_total_len = 0;
      int num_words = 0;
      int begin = 0;
      vector<string> result;
      if (words.size() == 1 && words[0].length() == 0) {
        string line;
        for (int i = 0; i < L; i++) {
          line += " ";
        }
        result.push_back(line);
        return result;
      }

      for (int i = 0; i < words.size(); i++) {
        string line("");
        words_total_len += words[i].length();
        num_words++;
        if (words_total_len + num_words - 1 > L) {
          words_total_len -= words[i].length();
          int num_spaces_line = L - words_total_len;
          num_words--;
          // cout << "num_spaces_line: " << num_spaces_line << endl;
          int num_spaces_base;
          if (num_words == 1)
            num_spaces_base = 0; 
          else
            num_spaces_base = num_spaces_line / (num_words - 1);
          // cout << "num_spaces_base: " << num_spaces_base << endl;
          // cout << "num_words: " << num_words << endl;
          int extra_spaces = num_spaces_line - num_spaces_base * (num_words - 1);
          for (int j = begin; j < i - 1; j++) {
            line += words[j];
            int num_spaces = num_spaces_base;
            if ((j - begin) < extra_spaces)
              num_spaces++;
            // cout << num_spaces << " ";
            for (int k = 0; k < num_spaces; k++) {
              line += " ";
            }
          }
          line += words[i - 1];
          if (num_words == 1)
            for (int k = 0; k < num_spaces_line; k++)
              line += " ";
          result.push_back(line);
          begin = i;
          words_total_len = words[i].length();
          num_words = 1;
        }
      }
      string line("");
      for (int i = begin; i < words.size(); i++) {
        line += words[i];
        if (i < words.size() - 1)
          line += " ";
      }
      // cout << line.length();
      int len = L - line.length();
      for (int i = 0; i < len; i++) {
        line += " ";
      }
      result.push_back(line);
      return result;
    }
};
int main() {
  Solution sol;
  vector<string> words {"Listen","to","many,","speak","to","a","few."};
  vector<string> result = sol.fullJustify(words, 6);
  cout << "=========================" << endl;
  for (int i = 0; i < result.size(); i++) 
    cout << result[i] << "%" << endl;
}
