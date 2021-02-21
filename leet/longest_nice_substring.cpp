#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <limits>
#include <map>
#include <memory>
#include <numeric>
#include <set>
#include <stack>
#include <utility>
#include <vector>

// Problem: https://leetcode.com/problems/longest-nice-substring/

typedef long long int llint;
typedef long double ldouble;

using namespace std;

class Solution {
 public:
  map<char, set<int>> locations;

  char __get_alternative__(const char c) {
    if (islower(c))
      return toupper(c);
    return tolower(c);
  }

  bool __is_break__(const char c, const int start, const int end) {
    const char target = __get_alternative__(c);
    const set<int>& locs = locations[target];
    if (locs.empty())
      return true;
    for (const int& i : locs) {
      if (i >= start and i < end)
        return false;
    }
    return true;
  }

  std::string __calc__(int start /*incl*/,
                       int end /*excl*/,
                       const std::string& input) {
    if (start >= end - 1)
      return "";

    const int orig_start = start;

    std::vector<std::pair<int, int>> subs;
    for (int i = start; i < end; i++) {
      if (__is_break__(input[i], start, end)) {
        subs.push_back({start, i});
        start = i + 1;
      }
    }
    if (start > orig_start and start < input.size())
      subs.push_back({start, end});

    std::string answer =
        subs.size() == 0 ? input.substr(start, end - start) : "";

    for (const pair<int, int>& i : subs) {
      std::string temp = __calc__(i.first, i.second, input);
      if (temp.size() > answer.size())
        answer = temp;
    }

    return answer;
  }

  string longestNiceSubstring(string s) {
    // trivial case.
    if (s.size() == 1)
      return "";

    // 1-time init ;
    for (int i = 0; i < s.size(); i++) {
      locations[s[i]].insert(i);
    }

    return __calc__(0, s.size(), s);
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  Solution temp;
  std::string input;
  std::cin >> input;
  std::string answer = temp.longestNiceSubstring(input);
  std::cout << "FINAL ANSWER : " << answer << std::endl;
  return 0;
}
