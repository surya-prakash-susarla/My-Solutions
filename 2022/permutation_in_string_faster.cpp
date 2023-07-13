#include <bits/stdc++.h>

using namespace std;

/*
"ab"
"cba"
"ab"
"eidbaooo"
"ab"
"eidboaoo"
"abcde"
"afbfcfdfef"
"a"
"zzzzzzzazzzz"
"efghijlk"
"kljihgfe"
"abc"
"ab"
"aaaaa"
"aaaaaaaa"
"hello"
"ooolleoooleh"
*/

class Solution {
 public:
  static const int maxvalue = numeric_limits<int>::max();

  class checker {
   public:
    explicit checker(const string& ref) {
      for (char c : ref)
        values[c - 'a']--;
      for (int& i : values)
        if (i == 0)
          i = maxvalue;
      req_value = 0 - (int)ref.size();
    }

    void dec(char c) {
      if (values[c - 'a'] == maxvalue)
        return;
      int& ref = values[c - 'a'];
      if (ref > 0) {
        ref--;
        return;
      } else {
        ref--;
        req_value--;
        return;
      }
    }

    void inc(char c) {
      if (values[c - 'a'] == maxvalue)
        return;
      int& ref = values[c - 'a'];
      if (ref >= 0) {
        ref++;
        return;
      } else {
        ref++;
        req_value++;
        return;
      }
    }

    inline bool is_done() { return req_value == 0; }

    int req_value = 0;
    vector<int> values = vector<int>(26, 0);
  };

  bool checkInclusion(string target, string input) {
    if (input.size() < target.size())
      return false;
    else if (input.size() == target.size()) {
      sort(input.begin(), input.end());
      sort(target.begin(), target.end());
      return input == target;
    }

    checker counter(target);
    int right = 0;
    for (; right < target.size(); right++) {
      counter.inc(input[right]);
    }
    if (counter.is_done())
      return true;
    for (; right < input.size(); right++) {
      counter.inc(input[right]);
      counter.dec(input[right - target.size()]);
      if (counter.is_done())
        return true;
    }

    return counter.is_done();
  }
};