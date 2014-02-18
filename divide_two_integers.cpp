#include <iostream>
using namespace std;
class Solution {
  public:
    int divide(int dividend, int divisor) {
      long long bit = 1;
      long long dividend_l = (long long)dividend;
      long long divisor_l = (long long)divisor;
      int answer = 0;
      int sig = 1;
      if (dividend_l < 0) {
        sig *= -1;
        dividend_l = -dividend_l;
      }
      if (divisor_l < 0) {
        sig *= -1;
        divisor_l = -divisor_l;
      }
      long long d = divisor_l;

      // cout << dividend_l << endl;
      // cout << divisor_l << endl;
      // cout << d << endl;
      while (d <= dividend_l) {
        d <<= 1;
        bit <<= 1;
      }
      d >>= 1;
      bit >>= 1;

      while (dividend_l >= divisor_l) {
        if (dividend_l >= d) {
          dividend_l -= d;
          answer |= bit;
        }
        d >>= 1;
        bit >>= 1;
      }
      return sig * answer;
    }
};

int main() {
  Solution sol;
  cout << sol.divide(-1010369383, -2147483648);

}
