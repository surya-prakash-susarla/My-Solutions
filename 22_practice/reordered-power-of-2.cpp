#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  typedef vector<int> vint;

  vint __get_freq__(int value) {
    vint answer(10, 0);
    while (value) {
      answer[value % 10]++;
      value /= 10;
    }
    return answer;
  }

  void __init__() {
    for (int i = 0; i < 31; i++)
      fmap[__get_freq__(1 << i)] = 1 << i;
  }

  bool reorderedPowerOf2(int n) {
    if (fmap.empty())
      __init__();
    auto it = fmap.find(__get_freq__(n));
    return it != fmap.end();
  }

  map<vint, int> fmap;
};
