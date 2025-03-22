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

  void make_set(int i,
                vector<int>& values,
                vector<bool>& visited,
                const vector<vector<bool>>& cons) {
    if (visited[i])
      return;
    values.push_back(i);
    visited[i] = true;
    for (int j = 0; j < n; j++)
      if (cons[i][j])
        make_set(j, values, visited, cons);
  }

  int countCompleteComponents(int n, vector<vector<int>>& input) {
    this->n = n;
    vector<vector<bool>> cons(n, vector<bool>(n, false));

    for (auto i : input) {
      cons[i[0]][i[1]] = true;
      cons[i[1]][i[0]] = true;
    }

    vector<bool> visited(n, false);

    auto get_node = [&]() -> int {
      for (int i = 0; i < n; i++)
        if (not visited[i])
          return i;
      return -1;
    };

    auto are_connected = [&](const vector<int>& values) -> bool {
      for (int i = 0; i < values.size(); i++) {
        for (int j = 0; j < values.size(); j++) {
          if (values[i] == values[j])
            continue;
          if (not cons[values[i]][values[j]])
            return false;
        }
      }
      return true;
    };

    int answer = 0;
    for (int current = get_node(); current != -1; current = get_node()) {
      vector<int> nodes;
      make_set(current, nodes, visited, cons);

      if (are_connected(nodes))
        answer++;
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
