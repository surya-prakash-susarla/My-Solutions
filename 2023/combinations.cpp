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
  typedef optional<vvint> ovvint;
  map<pair<int, int>, ovvint> memo;
  int limit;

  ovvint __rec__(int n, int k) {
    if (k == 0)
      return vvint();

    if (n == limit)
      return nullopt;

    auto it = memo.find(make_pair(n, k));
    if (it != memo.end())
      return it->second;

    ovvint incl = __rec__(n + 1, k - 1);
    ovvint excl = __rec__(n + 1, k);

    vvint answer;

    if (incl) {
      if (incl->size()) {
        for (auto& i : *incl) {
          i.push_back(n);
        }
      } else {
        incl = {{n}};
      }
      answer.insert(answer.end(), incl->begin(), incl->end());
    }

    if (excl)
      answer.insert(answer.end(), excl->begin(), excl->end());

    ovvint final_val = answer.empty() ? nullopt : ovvint(answer);
    memo[make_pair(n, k)] = final_val;
    return final_val;
  }

  vector<vector<int>> combine(int n, int k) {
    limit = n + 1;
    return *__rec__(1, k);
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
