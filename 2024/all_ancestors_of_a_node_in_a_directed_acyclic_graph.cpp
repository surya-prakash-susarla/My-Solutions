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
  vector<bool> visited;
  unordered_map<int, set<int>> memo;
  unordered_map<int, vector<int>> connections;

  set<int> __rec__(int index) {
    if (visited[index])
      return memo[index];

    visited[index] = true;

    set<int> answer;
    for (int i : connections[index]) {
      set<int> temp = __rec__(i);
      for (int j : temp)
        answer.insert(j);
      answer.insert(i);
    }

    memo[index] = answer;
    return answer;
  }

  vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
    visited = vector<bool>(n);
    for (const vector<int>& i : edges)
      connections[i[1]].push_back(i[0]);

    vector<vector<int>> answer(n);

    for (int i = 0; i < n; i++) {
      set<int> temp = __rec__(i);
      answer[i] = vector<int>(temp.begin(), temp.end());
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
