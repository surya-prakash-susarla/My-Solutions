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
  vector<int> subtree_vertex_count;
  vector<int> subtree_sum_of_distances;

  void fixed_center_sum(int current_node,
                        int parent,
                        const vector<list<int>>& cons) {
    for (int i : cons[current_node]) {
      if (i == parent)
        continue;
      fixed_center_sum(i, current_node, cons);
      subtree_vertex_count[current_node] += subtree_vertex_count[i];
      subtree_sum_of_distances[current_node] +=
          subtree_sum_of_distances[i] + subtree_vertex_count[i];
    }
  }

  void shift_centers(int current_node,
                     int parent,
                     const vector<list<int>>& cons) {
    for (int i : cons[current_node]) {
      if (i == parent)
        continue;
      subtree_sum_of_distances[i] = subtree_sum_of_distances[current_node] -
                                    subtree_vertex_count[i] + (cons.size()) -
                                    subtree_vertex_count[i];
      shift_centers(i, current_node, cons);
    }
  }

  vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
    subtree_vertex_count = vector<int>(n, 1);
    subtree_sum_of_distances = vector<int>(n, 0);
    vector<list<int>> cons(n);

    for (auto i : edges) {
      cons[i[0]].push_back(i[1]);
      cons[i[1]].push_back(i[0]);
    }

    fixed_center_sum(0, -1, cons);
    shift_centers(0, -1, cons);

    return subtree_sum_of_distances;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
