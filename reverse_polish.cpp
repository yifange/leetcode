#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <sstream>
#include <cassert>
using namespace std;
class Solution {
  public:
    bool is_number(string &s) {
      string::iterator it = s.begin();
      if (*it == '-')
        if (s.length() > 1)
          it++;
        else
          return false;
      while (it != s.end() && isdigit(*it)) 
        it++;
      return !s.empty() && it == s.end();
    }
    int evalRPN(vector<string> &tokens) {
      stack<int> s;
      for (int i = 0; i < tokens.size(); i++) {
        string token = tokens[i];
        if (is_number(tokens[i])) {
          istringstream convert(token);
          int number;
          convert >> number;
          s.push(number);
        } else {

          int r = s.top();
          s.pop();
          int l = s.top();
          s.pop();
          // cout << l << token << r;
          if (token == "+") 
            s.push(l + r);
          else if (token == "-") {
            s.push(l - r);
          }
          else if (token == "*")
            s.push(l * r);
          else if (token == "/") {
            s.push(l / r);
          }

        }
      } 
      return s.top();

    }
};
int main() {
  vector<string> tokens {"-78","-33","196","+","-19","-","115","+","-","-99","/","-18","8","*","-86","-","-","16","/","26","-14","-","-","47","-","101","-","163","*","143","-","0","-","171","+","120","*","-60","+","156","/","173","/","-24","11","+","21","/","*","44","*","180","70","-40","-","*","86","132","-84","+","*","-","38","/","/","21","28","/","+","83","/","-31","156","-","+","28","/","95","-","120","+","8","*","90","-","-94","*","-73","/","-62","/","93","*","196","-","-59","+","187","-","143","/","-79","-89","+","-"};
  // vector<string> tokens {"4", "3", "-"};
  Solution sol;
  cout << sol.evalRPN(tokens);
}
