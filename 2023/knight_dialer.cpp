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
  static constexpr int modvalue = 1000000007;
  map<pair<int, int>, int> memo;
  vector<vector<int>> values;

  int __rec__(int pos, int j) {
    if (j == 0) {
      return 1;
    }

    {
      auto it = memo.find({pos, j});
      if (it != memo.end())
        return it->second;
    }

    int answer = 0;

    for (int i : values[pos]) {
      answer += __rec__(i, j - 1);
      answer %= modvalue;
    }

    memo[{pos, j}] = answer;

    return answer;
  }

  int knightDialer(int n) {
    values.push_back({4, 6});
    values.push_back({6, 8});
    values.push_back({7, 9});
    values.push_back({4, 8});
    values.push_back({3, 9, 0});
    values.push_back({});
    values.push_back({1, 7, 0});
    values.push_back({2, 6});
    values.push_back({1, 3});
    values.push_back({2, 4});

    int answer = 0;

    for (int i = 0; i <= 9; i++) {
      answer += __rec__(i, n - 1);
      answer %= modvalue;
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
