#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int minSubArrayLen(int target, vector<int>& values) {
    const int maxvalue = numeric_limits<int>::max();

    int lp = 0;
    int rp = 0;
    int cs = values[0];
    int answer = maxvalue;

    for (int i = 0; i < values.size(); i++) {
      while (lp < i)
        cs -= values[lp++];
      if (rp < lp)
        rp = lp;
      while (cs < target and rp < values.size() - 1)
        cs += values[++rp];
      if (cs < target)
        break;
      answer = min(answer, rp - lp + 1);
    }

    return answer == maxvalue ? 0 : answer;
  }
};
