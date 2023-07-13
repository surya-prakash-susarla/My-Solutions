#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<vector<int>> subsetsWithDup(vector<int>& values) {
    typedef vector<int> vint;

    sort(values.begin(), values.end());

    vector<vint> answer = {{}};

    map<int, int> bounds;

    for (int i : values) {
      auto it = bounds.find(i);
      int limit = it == bounds.end() ? -1 : it->second;
      bounds[i] = answer.size() - 1;
      for (int j = answer.size() - 1; j > limit; j--) {
        vint temp(answer[j]);
        temp.push_back(i);
        answer.emplace_back(move(temp));
      }
    }

    return answer;
  }
};
