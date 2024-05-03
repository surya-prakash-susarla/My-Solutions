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
  bool is_valid(string s) {
    if (s.size() > 1 and s[0] == '0')
      return false;
    int value = 0;
    for (int i : s) {
      value = (value * 10) + (i - '0');
    }
    return value <= 255;
  }

  vector<string> restoreIpAddresses(string s) {
    if (s.size() > 12)
      return {};

    vector<string> answer;
    for (int i = 0; i < 3; i++) {
      string first = s.substr(0, i + 1);
      if (not is_valid(first))
        continue;
      first += '.';
      for (int j = i + 1; j < s.size() and j <= i + 3; j++) {
        string second = s.substr(i + 1, j - i);
        if (not is_valid(second))
          continue;
        second += '.';
        for (int k = j + 1; k < s.size() and k <= j + 3; k++) {
          string third = s.substr(j + 1, k - j);
          if (not is_valid(third))
            continue;
          third += '.';
          if (k + 1 >= s.size())
            continue;
          string fourth = s.substr(k + 1);
          if (not is_valid(fourth))
            continue;
          answer.emplace_back(first + second + third + fourth);
        }
      }
    }
    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
