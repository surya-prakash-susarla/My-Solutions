#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  bool checkPossibility(vector<int>& values) {
    bool used = false;

    int cmin = -100000;

    for (int i = 0; i < values.size() - 1; i++) {
      if (values[i] > values[i + 1]) {
        if (used)
          return false;

        if (values[i + 1] >= cmin) {
          values[i] = cmin;
        } else {
          values[i + 1] = values[i];
        }

        used = true;
      }
      cmin = values[i];
    }
    return true;
  }
};