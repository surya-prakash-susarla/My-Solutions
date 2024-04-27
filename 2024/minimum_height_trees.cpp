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
  vector<int> findMinHeightTrees(int n, vector<vector<int>>& input) {
    vector<int> deg(n, 0);
    vector<set<int>> cons(n);

    for (auto i : input) {
      deg[i[0]]++;
      deg[i[1]]++;
      cons[i[0]].insert(i[1]);
      cons[i[1]].insert(i[0]);
    }

    queue<int> leaves;
    for (int i = 0; i < n; i++)
      if (deg[i] == 1)
        leaves.push(i);

    for (int total_nodes = n; total_nodes > 2;) {
      queue<int> next_leaves;
      for (; not leaves.empty(); total_nodes--) {
        int current_leaf = leaves.front();
        leaves.pop();
        deg[current_leaf] = INT_MIN;
        for (int i : cons[current_leaf]) {
          if (deg[i] > 0 and --deg[i] == 1)
            next_leaves.push(i);
        }
      }
      swap(leaves, next_leaves);
    }

    vector<int> answer;
    for (int i = 0; i < n; i++)
      if (deg[i] != INT_MIN)
        answer.push_back(i);

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
