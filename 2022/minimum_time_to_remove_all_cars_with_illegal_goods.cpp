#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int minimumTime(string s) {
    vector<int> left(s.size(), 0);
    vector<int> right(s.size(), 0);

    left[0] = s[0] == '1' ? 1 : 0;
    for (int i = 1; i < s.size(); i++) {
      if (s[i] == '1') {
        left[i] = min(left[i - 1] + 2, i + 1);
      } else {
        left[i] = left[i - 1];
      }
    }

    right[s.size() - 1] = s[s.size() - 1] == '1' ? 1 : 0;
    for (int i = s.size() - 2; i >= 0; i--) {
      if (s[i] == '1') {
        right[i] = min(right[i + 1] + 2, (int)(s.size()) - i);
      } else {
        right[i] = right[i + 1];
      }
    }

    int answer = min(*left.rbegin(), *right.begin());
    for (int i = 0; i < s.size() - 1; i++) {
      answer = min(answer, left[i] + right[i + 1]);
    }

    return answer;
  }
};