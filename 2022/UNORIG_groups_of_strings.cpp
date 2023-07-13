#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  unordered_map<int, int> values;

  int paths(int mask) {
    int count = 0;
    auto it = values.find(mask);
    if (it != values.end()) {
      count += it->second;
      values.erase(it);
      for (int i = 0; i < 26; i++) {
        count += paths(mask ^ (1 << i));
        for (int j = i + 1; j < 26; j++) {
          if (((mask >> i) & 1) != ((mask >> j) & 1))
            count += paths(mask ^ (1 << i) ^ (1 << j));
        }
      }
    }
    return count;
  }

  vector<int> groupStrings(vector<string>& words) {
    for (const string& i : words)
      ++values[accumulate(i.begin(), i.end(), 0,
                          [](int m, char c) { return m | (1 << (c - 'a')); })];
    int gs = 0, ms = 0;
    while (!values.empty()) {
      int value = paths(values.begin()->first);
      ms = max(ms, value);
      gs += (value > 0);
    }
    return {gs, ms};
  }
};