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

  map<int, vint> values;
  vint answer;

  int __rec__(int n, vint& status) {
    // 0 -> yet to take
    // 1 -> solving right now
    // 2 -> done
    if (status[n] == 2)
      return 2;

    if (status[n] == 1)
      return 1;

    status[n] = 1;
    for (int i : values[n]) {
      int return_value = __rec__(i, status);
      if (return_value == 1)
        return 1;
    }

    status[n] = 2;
    answer.push_back(n);
    return 2;
  }

  vector<int> findOrder(int n, vector<vector<int>>& req) {
    for (int i = 0; i < n; i++)
      values[i];

    for (const vint& i : req)
      values[i[0]].push_back(i[1]);

    vint status(n);

    for (int i = 0; i < n; i++) {
      int return_value = __rec__(i, status);
      if (return_value == 1)
        return {};
    }

    return this->answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
