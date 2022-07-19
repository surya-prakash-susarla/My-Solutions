#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int _get_sum(int value) {
    int answer = 0;
    while (value > 0) {
      answer += (value % 10);
      value /= 10;
    }
    return answer;
  }

  int maximumSum(vector<int>& input) {
    map<int, multiset<int>> values;

    for (int i : input)
      values[_get_sum(i)].insert(i);

    int answer = -1;

    for (auto it : values) {
      if (it.second.size() > 1) {
        int current_sum = *it.second.rbegin() + *(next(it.second.rbegin(), 1));
        answer = max(answer, current_sum);
      }
    }

    return answer;
  }
};
