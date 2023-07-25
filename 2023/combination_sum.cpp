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
  typedef pair<int, int> pint;
  typedef optional<vvint> ovvint;

  map<pint, vvint> memo;

  vvint app(vint input, vvint values) {
    vvint answer;
    for (vint i : values) {
      vint temp = input;
      temp.insert(temp.end(), i.begin(), i.end());
      answer.emplace_back(temp);
    }
    return answer;
  }

  ovvint __rec__(int index, int req, const vint& input) {
    if (index == input.size()) {
      if (req == 0)
        return {};
      return nullopt;
    }

    {
      auto it = memo.find(make_pair(index, req));
      if (it != memo.end())
        return it->second;
    }

    ovvint exc = __rec__(index + 1, req, input);

    vvint inc;

    for (int i = 1;; i++) {
      int current = input[index] * i;
      if (current < req) {
        ovvint ret = __rec__(index + 1, req - current, input);
        if (ret) {
          vvint temp = app(vint(i, input[index]), *ret);
          inc.insert(inc.end(), temp.begin(), temp.end());
        }
      } else if (current == req) {
        inc.emplace_back(vint(i, input[index]));
      } else {
        break;
      }
    }

    if (exc)
      inc.insert(inc.end(), exc->begin(), exc->end());

    memo[make_pair(index, req)] = inc;

    return inc;
  }

  vector<vector<int>> combinationSum(vector<int>& values, int target) {
    ovvint answer = __rec__(0, target, values);
    if (answer)
      return *answer;
    return {};
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
