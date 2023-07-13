#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  bool isPowerOfThree(int n) {
    if (n <= 0)
      return false;
    constexpr int temp = 1162261467;
    return temp % n == 0;
  }
};
