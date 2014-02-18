#include <iostream>
#include <map>
using namespace std;
class Solution {
public:
    map<char, int>* get_need_to_find(string T) {
      map<char, int>* need_to_find = new map<char, int>();
      for (int i = 0; i < T.length(); i++) {
        map<char, int>::iterator it = need_to_find->find(T[i]);
        if (it != need_to_find->end()) {
          it->second++;
        } else {
          need_to_find->insert(make_pair(T[i], 1));
        }
      } 
      return need_to_find;
    } 
    string minWindow(string S, string T) {
      map<char, int>* need_to_find = get_need_to_find(T);        
      map<char, int>* has_found = new map<char, int>();
      for (map<char, int>::iterator it = need_to_find->begin(); it != need_to_find->end(); it++) {
        has_found->insert(make_pair(it->first, 0));
      }
      int count = 0;
      int head = 0;
      int m = S.length();
      int f = 0;
      int e = 0;
      for (int i = 0; i < S.length(); i++) {
        if (need_to_find->find(S[i]) != need_to_find->end()) {
          if (has_found->find(S[i])->second < need_to_find->find(S[i])->second)
            count++;
          has_found->find(S[i])->second++;
          if (count >= T.length()) {
            while (head < i) {
              if (need_to_find->find(S[head]) != need_to_find->end()) {
                if (has_found->find(S[head])->second > need_to_find->find(S[head])->second) {
                  has_found->find(S[head])->second--;
                  head++;
                } else {
                  break;
                }
              }
            }
            if (i - head + 1 < m) {
              f = head;
              e = i;
              m = i - head + 1;
            }
          }
        }
      }
      return S.substr(f, m);
    }
};

int main() {
  Solution sol;

  cout << sol.minWindow(string("ADOBECODEBANC"), string("ABC"));
}
