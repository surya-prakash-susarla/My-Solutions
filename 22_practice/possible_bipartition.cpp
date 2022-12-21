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
  int n;

  vector<int> parents;
  vector<bool> visited;

  unordered_map<int, vector<int>> cons;

  bool setup(int index, int target) {
    if (visited[index])
      return true;
    visited[index] = true;

    for (int i : cons[index]) {
      if (parents[i] == -1)
        parents[i] = target;
      else if (parents[i] != target)
        return false;
      if (not setup(i, target == 1 ? 2 : 1))
        return false;
    }

    return true;
  }

  bool possibleBipartition(int k, vector<vector<int>>& dislikes) {
    this->n = k + 1;
    parents = vector<int>(n, -1);
    visited = vector<bool>(n, false);
    for (const vector<int>& i : dislikes) {
      cons[i[0]].push_back(i[1]);
      cons[i[1]].push_back(i[0]);
    }

    auto get_index = [&]() -> int {
      for (int i = 1; i < n; i++)
        if (not visited[i])
          return i;
      return -1;
    };

    int index = get_index();

    while (index != -1) {
      parents[index] = 1;
      if (not setup(index, 2))
        return false;
      index = get_index();
    }

    return true;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
