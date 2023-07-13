#include <bits/stdc++.h>

using namespace std;

/*
Tests:
"abcabcbb"
"bbbbb"
"pwwkew"
"a"
"abcdefghijklmnopqrstuvwxyz"
"_+-_abcdefghijklmnopqrstuvwxyz"
"aabaab!bb"
*/

class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    map<char, int> locations;
    int answer = 0;
    int current_length = 0;
    for (int i = 0; i < s.size(); i++) {
      auto it = locations.find(s[i]);
      if (it == locations.end()) {
        locations[s[i]] = i;
        answer = max(answer, ++current_length);
      } else {
        current_length = i - it->second;
        answer = max(answer, current_length);
        const int required_index = it->second;
        for (auto jt = locations.begin(); jt != locations.end();) {
          if (jt->second <= required_index) {
            jt = locations.erase(jt);
          } else {
            jt++;
          }
        }
        locations[s[i]] = i;
      }
    }
    return answer;
  }
};
