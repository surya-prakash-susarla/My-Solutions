#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  bool isAnagram(string s, string t) {
    if (s.size() != t.size())
      return false;
    vector<int> values(26, 0);
    for (char c : s)
      values[c - 'a']++;
    for (char c : t)
      if (values[c - 'a'] > 0)
        values[c - 'a']--;
      else
        return false;
    return true;
  }
};
