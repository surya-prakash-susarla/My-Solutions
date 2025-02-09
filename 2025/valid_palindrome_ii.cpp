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
  bool __rec__(int left, int right, const string& s, bool used) {
    if (left > right)
      return true;

    if (s[left] == s[right]) {
      return __rec__(left + 1, right - 1, s, used);
    }

    if (used)
      return false;

    return __rec__(left + 1, right, s, true) or
           __rec__(left, right - 1, s, true);
  }

  bool validPalindrome(string s) { return __rec__(0, s.size() - 1, s, false); }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
