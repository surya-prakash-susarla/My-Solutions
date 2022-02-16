#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int findPairs(vector<int>& nums, int k) {
    map<int, int> values;
    for (int i : nums)
      values[i]++;

    int answer = 0;
    if (k == 0) {
      for (pair<int, int> i : values)
        if (i.second > 1)
          answer++;
      return answer;
    } else {
      for (pair<int, int> i : values) {
        auto it = values.find(i.first + k);
        if (it != values.end())
          answer++;
        it = values.find(i.first - k);
        if (it != values.end())
          answer++;
        values.erase(i.first);
      }
      return answer;
    }
  }
};