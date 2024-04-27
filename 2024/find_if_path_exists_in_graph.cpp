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
  map<int, list<int>> cons;
  int n;

  bool __rec__(int current, const int dest) {
    if (visited[current])
      return false;
    visited[current] = true;
    if (current == dest)
      return true;

    for (int i : cons.find(current)->second)
      if (not visited[i] and __rec__(i, dest))
        return true;

    return false;
  }

  bool validPath(int n,
                 vector<vector<int>>& edges,
                 int source,
                 int destination) {
    // vector<vector<int>> cons(n, vector<int>(n, -1));
    for (auto i : edges) {
      // cons[i[0]][i[1]] = 1;
      // cons[i[1]][i[0]] = 1;
      cons[i[0]].push_back(i[1]);
      cons[i[1]].push_back(i[0]);
    }

    this->n = n;
    visited = vector<bool>(n, false);

    return __rec__(source, destination);
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
