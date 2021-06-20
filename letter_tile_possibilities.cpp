#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  set<string> values;

  void calc(string current, map<char, int> chars) {
    values.insert(current);
    for (map<char, int>::iterator it = chars.begin(); it != chars.end(); it++)
      if (it->second != 0) {
        it->second -= 1;
        calc(current + it->first, chars);
        it->second += 1;
      }
  }

  int numTilePossibilities(string tiles) {
    map<char, int> mapValues;
    for (char i : tiles)
      mapValues[i] += 1;
    calc(string(), mapValues);
    return values.size() - 1;
  }
};