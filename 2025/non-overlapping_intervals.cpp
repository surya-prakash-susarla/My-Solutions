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
  typedef vector<int> vint;
  typedef vector<vint> vvint;

  vvint input;
  map<int, int> locs;

  vector<int> memo;

  int __rec__(int index) {
    if (index == input.size())
      return 0;

    if (memo[index] != -1)
      return memo[index];

    // incl
    int incl = 1;
    {
      int end = input[index][1];
      auto next = locs.lower_bound(end);
      if (next != locs.end())
        incl += __rec__(next->second);
    }

    // excl
    const int excl = __rec__(index + 1);
    int answer = max(incl, excl);
    memo[index] = answer;
    return answer;
  }

  int eraseOverlapIntervals(vector<vector<int>>& input) {
    sort(input.begin(), input.end(), [](const vint& a, const vint& b) {
      if (a[0] == b[0])
        return a[1] < b[1];
      return a[0] < b[0];
    });

    this->input = input;

    memo = vector<int>(input.size(), -1);

    for (int i = input.size() - 1; i > -1; i--)
      locs[input[i][0]] = i;

    int maxlen = __rec__(0);

    return input.size() - maxlen;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
