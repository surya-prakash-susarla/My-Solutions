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
  map<int, int> memo;

  inline int upbound(int value, const vint& values) {
    auto it = upper_bound(values.begin(), values.end(), value);
    return it == values.end() ? values.size() : (it - values.begin());
  }

  int __rec__(int index, const vint& values, const vint& costs) {
    if (index == values.size())
      return 0;

    auto it = memo.find(index);
    if (it != memo.end())
      return it->second;

    const int daily = costs[0] + __rec__(index + 1, values, costs);
    const int weekly =
        costs[1] + __rec__(upbound(values[index] + 6, values), values, costs);
    const int monthly =
        costs[2] + __rec__(upbound(values[index] + 29, values), values, costs);

    const int answer = min({daily, weekly, monthly});
    memo[index] = answer;
    return answer;
  }

  int mincostTickets(vector<int>& days, vector<int>& costs) {
    return __rec__(0, days, costs);
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
