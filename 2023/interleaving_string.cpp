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
  map<vint, bool> memo;

  string a, b, t;

  bool __rec__(int ti, int ai, int bi) {
    if (ti == t.size())
      return ai == a.size() and bi == b.size();

    if (ai == a.size() and bi == b.size())
      return false;

    {
      auto it = memo.find({ti, ai, bi});
      if (it != memo.end())
        return it->second;
    }

    bool answer = false;
    if (t[ti] == a[ai]) {
      answer |= __rec__(ti + 1, ai + 1, bi);
    }
    if (not answer and t[ti] == b[bi]) {
      answer |= __rec__(ti + 1, ai, bi + 1);
    }

    memo[{ti, ai, bi}] = answer;
    return answer;
  }

  bool isInterleave(string a, string b, string target) {
    this->a = a;
    this->b = b;
    t = target;
    return __rec__(0, 0, 0);
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
