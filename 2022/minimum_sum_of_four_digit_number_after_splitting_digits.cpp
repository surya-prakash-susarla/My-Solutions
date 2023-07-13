#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int minimumSum(int num) {
    string digits = to_string(num);
    sort(digits.begin(), digits.end());
    string a(2, '_');
    string b(2, '_');
    a[1] = digits[3];
    b[1] = digits[2];
    a[0] = digits[1];
    b[0] = digits[0];
    return stoi(a) + stoi(b);
  }
};