#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int minPartitions(string n) {
    int maxvalue = 0;
    for (char c : n)
      maxvalue = max(maxvalue, c - '0');
    return maxvalue;
  }
};