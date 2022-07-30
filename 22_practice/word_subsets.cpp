#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  typedef vector<int> vint;

  vector<string> wordSubsets(vector<string>& input, vector<string>& values) {
    typedef vector<int> vint;
    vint value_map(26, 0);

    for (const string& i : values)
      update_map(i, value_map);

    vector<string> answer;
    for (const string& j : input) {
      vint temp(26, 0);
      for (char c : j)
        temp[c - 'a']++;

      bool valid = true;
      for (int i = 0; i < 26; i++) {
        if (temp[i] < value_map[i]) {
          valid = false;
          break;
        }
      }

      if (valid)
        answer.push_back(j);
    }

    return answer;
  }

  void update_map(const string& input, vint& ref) {
    vint temp(26, 0);
    for (char c : input) {
      int ind = c - 'a';
      temp[ind]++;
      ref[ind] = max(ref[ind], temp[ind]);
    }
  }
};
