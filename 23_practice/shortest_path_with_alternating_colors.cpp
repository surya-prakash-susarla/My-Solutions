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
  typedef vector<int> vint;
  typedef vector<vint> vvint;
  typedef pair<int, int> pint;
  typedef vector<pint> vpint;

  static constexpr int maxvalue = numeric_limits<int>::max();

  vpint __find_paths__(bool is_red,
                       const int n,
                       const vvint& red,
                       const vvint& blue) {
    vpint answer(n, make_pair(maxvalue, maxvalue));
    if (not is_red)
      answer[0] = make_pair(0, maxvalue);
    else
      answer[0] = make_pair(maxvalue, 0);

    queue<int> nodes;
    nodes.push(0);

    bool current_red = is_red;

    while (not nodes.empty()) {
      queue<int> next_nodes;
      while (not nodes.empty()) {
        int current = nodes.front();
        if (current_red) {
          for (int i = 0; i < n; i++) {
            if (red[current][i] != maxvalue) {
              if (answer[current].second + red[current][i] < answer[i].first) {
                answer[i].first = answer[current].second + red[current][i];
                next_nodes.push(i);
              }
            }
          }
        } else {
          for (int i = 0; i < n; i++) {
            if (blue[current][i] != maxvalue) {
              if (answer[current].first + blue[current][i] < answer[i].second) {
                answer[i].second = answer[current].first + blue[current][i];
                next_nodes.push(i);
              }
            }
          }
        }
        nodes.pop();
      }
      current_red = not current_red;
      swap(next_nodes, nodes);
    }

    return answer;
  }

  vector<int> shortestAlternatingPaths(int n,
                                       vector<vector<int>>& redEdges,
                                       vector<vector<int>>& blueEdges) {
    vvint red(n, vint(n, maxvalue));
    vvint blue(n, vint(n, maxvalue));
    for (const vint& i : redEdges) {
      red[i[0]][i[1]] = 1;
    }
    for (const vint& i : blueEdges) {
      blue[i[0]][i[1]] = 1;
    }
    vpint red_paths = __find_paths__(true, n, red, blue);
    vpint blue_paths = __find_paths__(false, n, red, blue);
    vint answer(n);
    for (int i = 0; i < n; i++) {
      answer[i] = min({red_paths[i].first, red_paths[i].second,
                       blue_paths[i].first, blue_paths[i].second});
      if (answer[i] == maxvalue)
        answer[i] = -1;
    }
    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
