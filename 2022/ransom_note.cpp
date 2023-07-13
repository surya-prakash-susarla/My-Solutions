#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  bool canConstruct(string ransomNote, string magazine) {
    vector<int> values(26, 0);
    for (char c : magazine)
      values[c - 'a']++;

    for (char c : ransomNote) {
      if (values[c - 'a'] == 0)
        return false;
      values[c - 'a']--;
    }

    return true;
  }
};
