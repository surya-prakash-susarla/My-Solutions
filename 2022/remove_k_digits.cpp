#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  string removeKdigits(string num, int k) {
    if (num.size() <= k)
      return "0";

    const int final_size = num.size() - k;
    string answer(final_size, ' ');

    for (int ai = 0, ci = 0; ai < final_size; ai++) {
      int fi = ci;
      for (int j = ci; j <= ci + k; j++)
        if (num[j] < num[fi])
          fi = j;
      answer[ai] = num[fi];
      k -= (fi - ci);
      ci = fi != ci ? fi + 1 : ci + 1;
    }

    int i = 0;
    for (; answer[i] == '0'; i++)
      ;
    return i < answer.size() ? answer.substr(i, answer.size() - i) : "0";
  }
};