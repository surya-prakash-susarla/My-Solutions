#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  bool isHappy(int n) {
    set<int> values;

    while (values.find(n) == values.end()) {
      int sum = 0;
      values.insert(n);
      while (n != 0) {
        int digit = n % 10;
        sum += (digit * digit);
        n /= 10;
      }
      if (sum == 1)
        return true;
      n = sum;
      // cout << "n value : " << n << endl;
    }

    return false;
  }
};
