#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  bool isPowerOfFour(int n) { return fmod(log2(n), 2) == 0.0; }
};
