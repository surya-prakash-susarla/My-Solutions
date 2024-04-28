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

  bool __rec__(int i, int j, const string& s) {
    if (i >= j)
      return true;
    if (memo[i][j] != -1)
      return (bool)memo[i][j];

    memo[i][j] = ((s[i] == s[j]) and (__rec__(i + 1, j - 1, s)));
    return memo[i][j];
  }

  string longestPalindrome(string s) {
    memo = vector<vector<int>>(s.size(), vector<int>(s.size(), -1));
    for (int i = 0; i < s.size(); i++)
      memo[i][i] = 1;

    int start = 0;
    int end = 0;

    for (int i = 0; i < s.size(); i++)
      for (int j = i + 1; j < s.size(); j++)
        if (__rec__(i, j, s) and (j - i + 1) > (end - start + 1)) {
          start = i;
          end = j;
        }

    return s.substr(start, end - start + 1);
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
