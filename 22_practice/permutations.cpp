#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<vector<int>> permute(vector<int>& values) {
    typedef vector<int> vint;

    vector<vint> current = {{values[0]}};

    for (int i = 1; i < values.size(); i++) {
      vector<vint> nc;
      for (vint j : current) {
        for (int k = 0; k <= j.size(); k++) {
          vint temp = j;
          temp.insert(temp.begin() + k, values[i]);
          nc.emplace_back(move(temp));
        }
      }
      swap(current, nc);
    }

    return current;
  }
};