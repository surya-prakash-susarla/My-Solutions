#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#include <vector>

// Problem:

typedef long long int llint;
typedef long double ldouble;

using namespace std;

class Solution {
 public:
  int target = -1;
  vector<vector<bool>> memo;

  const int maxval = numeric_limits<int>::max();

  int __rec__(const int start) {
    vector<int> dist(memo.size(), maxval);
    vector<bool> use(memo.size(), false);

    dist[start] = 1;

    auto get_val = [&]() -> int {
      int m = maxval;
      int mi = -1;
      for (int i = 0; i < memo.size(); i++)
        if (!use[i] && dist[i] < m) {
          m = dist[i];
          mi = i;
        }
      return mi;
    };

    for (int ind = get_val(); ind != -1; ind = get_val()) {
      use[ind] = true;
      for (int i = 0; i < memo.size(); i++)
        if (memo[ind][i] and not use[i] and dist[ind] + 1 < dist[i])
          dist[i] = dist[ind] + 1;
    }

    return dist[target];
  }

  bool are_connected(const string& a, const string& b) {
    bool chance = true;
    for (int i = 0; i < a.size(); i++)
      if (a[i] != b[i]) {
        if (chance)
          chance = false;
        else
          return false;
      }
    return !chance;
  }

  int ladderLength(const string& start,
                   const string& end,
                   vector<string>& list) {
    auto it = find(list.begin(), list.end(), start);
    int ind = -1;
    if (it == list.end()) {
      list.push_back(start);
      ind = list.size() - 1;
    } else {
      ind = it - list.begin();
    }

    memo = vector<vector<bool>>(list.size(), vector<bool>(list.size(), false));

    for (int i = 0; i < list.size(); i++) {
      if (list[i] == end)
        target = i;
      for (int j = i + 1; j < list.size(); j++) {
        if (are_connected(list[i], list[j])) {
          memo[i][j] = true;
          memo[j][i] = true;
        }
      }
    }

    if (target == -1)
      return 0;

    const int answer = __rec__(ind);
    return answer == maxval ? 0 : answer;
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);

  return 0;
}
