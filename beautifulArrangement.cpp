#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int result = 0;

  void calc(int value,
            vector<bool> current,
            const int& limit,
            const vector<set<int>>& stored) {
    if (value > limit) {
      result += 1;
      return;
    }
    for (auto i : stored[value]) {
      if (not current[i]) {
        current[i] = true;
        calc(value + 1, current, limit, stored);
        current[i] = false;
      }
    }
  }

  int countArrangement(int val) {
    vector<set<int>> stored(val + 1);
    for (int i = 1; i <= val; i++) {
      for (int j = 1; j * i <= val; j++) {
        stored[i].insert(i * j);
        stored[i * j].insert(i);
      }
    }

    calc(1, vector<bool>(val + 1, false), val, stored);
    return result;
  }
};