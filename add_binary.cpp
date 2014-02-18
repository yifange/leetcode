#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size();
        int j = b.size();
        int carry = 0;
        while (i >= 0 && j >= 0) {
            int result = a[i] - '0' + b[j] - '0' + carry;
        }
    }
};
