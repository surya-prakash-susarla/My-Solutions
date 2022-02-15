#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  bool checkInclusion(string a, string b) {
    if (a.size() > b.size())
      return false;
    if (a.size() == b.size()) {
      sort(a.begin(), a.end());
      sort(b.begin(), b.end());
      return a == b;
    }

    vector<int> a_values(26, 0);
    vector<int> b_values(26, 0);

    for (char c : a)
      a_values[c - 'a']++;

    for (int i = 0; i < a.size(); i++)
      b_values[b[i] - 'a']++;

    if (a_values == b_values)
      return true;

    for (int i = a.size(); i < b.size(); i++) {
      b_values[b[i - a.size()] - 'a']--;
      b_values[b[i] - 'a']++;
      if (a_values == b_values)
        return true;
    }

    return false;
  }
};
