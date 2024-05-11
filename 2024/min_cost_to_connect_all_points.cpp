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
  typedef long long int llint;

  inline llint dist(const vector<int>& a, const vector<int>& b) {
    return abs(a[0] - b[0]) + abs(a[1] - b[1]);
  }

  int minCostConnectPoints(vector<vector<int>>& points) {
    const int n = points.size();

    vector<vector<llint>> cons(n, vector<llint>(n, INT_MAX));

    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        cons[i][j] = dist(points[i], points[j]);
        cons[j][i] = cons[i][j];
      }
    }

    vector<bool> visited(n, false);
    llint answer = 0;
    visited[0] = true;

    priority_queue<pair<llint, int>, vector<pair<llint, int>>,
                   greater<pair<llint, int>>>
        edges;

    for (int i = 0; i < n; i++) {
      if (not visited[i])
        edges.push(make_pair(cons[0][i], i));
    }

    for (int _ = 0; _ < n and not edges.empty(); _++) {
      pair<int, int> current;
      do {
        current = edges.top();
        edges.pop();
      } while (not edges.empty() and visited[current.second]);
      if (edges.empty() and visited[current.second])
        break;
      answer += current.first;
      visited[current.second] = true;
      for (int i = 0; i < n; i++)
        if (not visited[i])
          edges.push(make_pair(cons[current.second][i], i));
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
