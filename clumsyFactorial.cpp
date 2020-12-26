#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int ins(int index) {
    if (index == 1)
      return 1;
    else if (index == 2)
      return 2 * 1;
    return (index * (index - 1)) / (index - 2);
  }

  int clumsy(int limit) {
    int answer = ins(limit);
    bool add = true;
    for (int i = limit - 3; i > 0; i--)
      if (add) {
        answer += i;
        add = false;
      } else {
        answer = answer - ins(i);
        i -= 2;
        add = true;
      }
    return answer;
  }
};