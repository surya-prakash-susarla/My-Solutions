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
  typedef long long ll;

  vector<ll> memo;

  ll __rec__(int index, const vector<vector<int>>& input) {
    if (index >= input.size())
      return 0;

    if (memo[index] != -1)
      return memo[index];

    ll incl = input[index][0] + __rec__(index + input[index][1] + 1, input);
    ll excl = __rec__(index + 1, input);

    memo[index] = max(incl, excl);
    return memo[index];
  }

  long long mostPoints(vector<vector<int>>& questions) {
    memo = vector<ll>(questions.size(), -1);
    return __rec__(0, questions);
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
