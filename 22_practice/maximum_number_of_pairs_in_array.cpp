#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<int> numberOfPairs(vector<int>& input) {
    map<int, int> values;
    for (int i : input)
      values[i]++;

    vector<int> answer(2);

    for (auto it : values) {
      answer[0] += (it.second / 2);
      answer[1] += (it.second % 2);
    }

    return answer;
  }
};
