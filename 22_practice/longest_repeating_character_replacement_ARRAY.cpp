#include <bits/stdc++.h>

using namespace std;

/*
Test cases:
"ABAB"
2
"AABABBA"
1
"AABBB"
1
*/

class Solution {
 public:
  class CharMap {
   public:
    CharMap() { values = vector<int>(26, 0); }

    void incCount(char c) { values[c - 'A']++; }

    void decCount(char c) { values[c - 'A']--; }

    int maxCount() { return *max_element(values.begin(), values.end()); }

   private:
    vector<int> values;
  };

  int characterReplacement(string input, int k) {
    CharMap values;

    int answer = 0;
    int left = 0;

    for (int i = 0; i < input.size(); i++) {
      values.incCount(input[i]);
      int mc = values.maxCount();
      while ((i - left + 1) - mc > k) {
        values.decCount(input[left++]);
      }
      answer = max(answer, (i - left + 1));
    }

    return answer;
  }
};