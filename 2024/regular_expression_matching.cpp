#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

typedef long long int llint;
typedef long long unsigned int ullint;

using namespace std;

class Solution {
 public:
  vector<vector<int>> memo;

  inline bool is_matching(char a, char b) { return b == '.' or a == b; }

  bool can_skip_pattern(int pi, const vector<pair<char, char>>& pattern) {
    while (pi < pattern.size()) {
      if (pattern[pi].second == '*')
        pi++;
      else
        break;
    }
    return pi == pattern.size();
  }

  bool __rec__(int si,
               int pi,
               const string& input,
               const vector<pair<char, char>>& pattern) {
    if (pi == pattern.size())
      return si == input.size();

    if (si == input.size())
      return can_skip_pattern(pi, pattern);

    if (memo[si][pi] != -1)
      return (bool)memo[si][pi];

    bool answer = false;

    if (pattern[pi].second == '*') {
      answer |= __rec__(si, pi + 1, input, pattern);
      answer |= is_matching(input[si], pattern[pi].first) and
                __rec__(si + 1, pi, input, pattern);
    } else {
      answer |= is_matching(input[si], pattern[pi].first) and
                __rec__(si + 1, pi + 1, input, pattern);
    }

    memo[si][pi] = answer;
    return answer;
  }

  bool isMatch(string s, string p) {
    vector<pair<char, char>> pattern;
    for (int i = 0; i < p.size(); i++) {
      if (p[i] == '*')
        pattern.rbegin()->second = '*';
      else
        pattern.push_back(make_pair(p[i], '-'));
    }
    memo = vector<vector<int>>(s.size(), vector<int>(pattern.size(), -1));
    return __rec__(0, 0, s, pattern);
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
