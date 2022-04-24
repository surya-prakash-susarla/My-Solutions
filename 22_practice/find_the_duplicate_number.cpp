#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int findDuplicate(vector<int>& input) {
    auto countLower = [&](int value) -> int {
      int count = 0;
      for (int i : input)
        if (i <= value)
          count++;
      return count;
    };

    int low = 0;
    int high = input.size();
    int answer = -1;

    while (low <= high) {
      int cval = (high + low) / 2;
      if (countLower(cval) > cval) {
        answer = cval;
        high = cval - 1;
      } else {
        low = cval + 1;
      }
    }

    return answer;
  }
};
