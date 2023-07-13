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
  vector<optional<bool>> memo;
  int n;

  static constexpr int __m = 10001;
  typedef bitset<__m> bs;

  bool __rec__(int index, bs& visited, const vector<vector<int>>& values) {
    if (memo[index])
      return *memo[index];

    if (visited[index])
      return true;

    visited[index] = true;

    bool is_unsafe = false;
    for (int i : values[index]) {
      is_unsafe |= __rec__(i, visited, values);
    }

    visited[index] = false;
    memo[index] = is_unsafe;

    return is_unsafe;
  }

  inline optional<int> get() {
    for (int i = 0; i < n; i++)
      if (not memo[i])
        return i;
    return nullopt;
  }

  vector<int> eventualSafeNodes(vector<vector<int>>& values) {
    n = values.size();
    memo = vector<optional<bool>>(n);

    optional<int> ind = get();
    bs visited;

    while (ind) {
      __rec__(*ind, visited, values);
      ind = get();
    }

    vector<int> answer;
    for (int i = 0; i < n; i++)
      if (*memo[i] == false)
        answer.push_back(i);

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
