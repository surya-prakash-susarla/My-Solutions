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
  unordered_map<int, unordered_map<int, unordered_map<int, bool>>> memo;

  bool __rec__(int l, int r, int k, const string& s) {
    if (l >= r)
      return true;

    {
      auto it = memo[l][r].find(k);
      if (it != memo[l][r].end())
        return it->second;
    }

    bool answer = false;
    if (s[l] == s[r]) {
      answer = __rec__(l + 1, r - 1, k, s);
    } else if (k > 0) {
      answer = __rec__(l + 1, r, k - 1, s) or __rec__(l, r - 1, k - 1, s);
    }

    memo[l][r][k] = answer;
    return answer;
  }

  bool isValidPalindrome(string s, int k) {
    return __rec__(0, s.size() - 1, k, s);
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
