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

  int __rec__(int i, int j, const string& value_1, const string& value_2) {
    if (i >= value_1.size() or j >= value_2.size())
      return 0;
    if (memo[i][j] != -1)
      return memo[i][j];
    int& return_value = memo[i][j];
    if (value_1[i] == value_2[j]) {
      return_value = __rec__(i + 1, j + 1, value_1, value_2) + 1;
    } else {
      return_value = max(__rec__(i + 1, j, value_1, value_2),
                         __rec__(i, j + 1, value_1, value_2));
    }
    return return_value;
  }

  int longestCommonSubsequence(string value_1, string value_2) {
    memo = vector<vector<int>>(value_1.size(), vector<int>(value_2.size(), -1));
    return __rec__(0, 0, value_1, value_2);
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
