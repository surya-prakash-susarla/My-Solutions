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
  typedef vector<double> vd;
  typedef vector<bool> vb;
  typedef pair<double, double> pd;

  double maxProbability(int n,
                        vector<vector<int>>& edges,
                        vector<double>& prob,
                        int start,
                        int end) {
    priority_queue<pd> qu;
    unordered_map<int, vector<pd>> cons;

    for (int i = 0; i < edges.size(); i++) {
      int first = edges[i][0];
      int second = edges[i][1];
      cons[first].emplace_back(make_pair(second, prob[i]));
      cons[second].emplace_back(make_pair(first, prob[i]));
    }

    vd dist(n, 0);
    vb visited(n, false);

    dist[start] = 1;
    qu.push(make_pair(1, start));

    while (not qu.empty()) {
      pd current = qu.top();
      qu.pop();
      visited[current.second] = true;

      if (current.second == end)
        return current.first;

      for (const pd& i : cons[current.second]) {
        const double upd = current.first * i.second;
        if (not visited[i.first] and dist[i.first] < upd) {
          dist[i.first] = upd;
          qu.push(make_pair(upd, i.first));
        }
      }
    }

    return dist[end];
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
