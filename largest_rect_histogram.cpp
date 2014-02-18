#include <iostream>
#include <vector>
#include <stack>
#include <tuple>
using namespace std;

class Solution {
  public:
    int largestRectangleArea(vector<int> &height) {
      stack<tuple<int, int> > s;
      s.push(make_tuple(-1, 0));
      height.push_back(0);
      int max = 0;
      for (int i = 0; i < height.size(); i++) {
        if (height[i] >= get<0>(s.top())) {
          cout << "pushing: " << height[i] << " * 1" << endl;
          s.push(make_tuple(height[i], 1));
        } else {
          int width = 1;
          while (height[i] <= get<0>(s.top())) {
            int h = get<0>(s.top());
            width += get<1>(s.top());
            if (h * (width - 1) > max)
              max = h * (width - 1);
            s.pop();
          }
          cout << "pushing: " << height[i] << " * " << width << endl;
          s.push(make_tuple(height[i], width));
        }
      }
      return max;
    }
};

int main() {
  Solution sol;
  vector<int> heights {1, 2, 3, 4, 5, 6};
  cout << sol.largestRectangleArea(heights) << endl;
}
