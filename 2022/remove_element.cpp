#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int removeElement(vector<int>& input, int val) {
    if (input.size() == 0)
      return 0;

    int lp = -1;
    int hp = -1;

    const int sv = input.size();

    while (++lp < sv and input[lp] != val)
      ;
    if (lp == sv)
      return sv;

    hp = lp;
    while (++hp < sv and input[hp] == val)
      ;
    if (hp == sv)
      return lp;

    while (hp < sv and input[hp] != val) {
      swap(input[lp], input[hp]);
      while (input[++lp] != val)
        ;
      while (hp < sv - 1 and input[++hp] == val)
        ;
    }

    return lp;
  }
};