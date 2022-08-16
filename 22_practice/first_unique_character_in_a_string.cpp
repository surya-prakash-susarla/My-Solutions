#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int firstUniqChar(string s) {
    stack<pair<char, int>> locs;
    vector<int> used(26, 0);

    for (int i = 0; i < s.size(); i++) {
      int ind = s[i] - 'a';
      if (used[ind] == 2) {
        continue;
      } else if (used[ind] == 1) {
        used[ind] = 2;
      } else {
        used[ind] = 1;
        locs.push({s[i], i});
      }
    }

    int ind = -1;
    while (not locs.empty()) {
      if (used[locs.top().first - 'a'] == 1)
        ind = locs.top().second;
      locs.pop();
    }

    return ind;
  }
};
