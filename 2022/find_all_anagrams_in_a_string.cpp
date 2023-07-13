#include <bits/stdc++.h>

using namespace std;

/*
"cbaebabacd"
"abc"
"abab"
"ab"
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

    inline bool is_done(char c) {
      return values[c - 'a'] == 0 && req_value == 0;
    }

    int req_value = 0;
    vector<int> values = vector<int>(26, 0);
  };

  vector<int> findAnagrams(string input, string target) {
    if (input.size() < target.size())
      return {};
    else if (input.size() == target.size()) {
      sort(input.begin(), input.end());
      sort(target.begin(), target.end());
      return input == target ? vector<int>(1, 0) : vector<int>();
    }

    vector<int> answer;
    checker counter(target);
    int right = 0;
    for (; right < target.size(); right++) {
      counter.inc(input[right]);
    }
    if (counter.is_done(input[right - 1]))
      answer.push_back(0);
    for (; right < input.size(); right++) {
      counter.inc(input[right]);
      counter.dec(input[right - target.size()]);
      if (counter.is_done(input[right])) {
        answer.push_back(right - target.size() + 1);
      }
    }

    return answer;
  }
};