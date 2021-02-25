#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#include <vector>

// Problem: https://leetcode.com/problems/map-of-highest-peak/submissions/
// Bi-weekly Contest 46
// Multi-source BFS

typedef long long int llint;
typedef long double ldouble;

using namespace std;

class Solution {
 public:
  using pint = pair<int, int>;

  inline void __update__(const int x,
                         const int y,
                         vector<vector<bool>>& visited,
                         queue<pint>& answer) {
    if (x > -1 and x < visited.size() and y > -1 and y < visited[0].size() and
        !visited[x][y]) {
      answer.push({x, y});
      visited[x][y] = true;
    }
  }

  void __gen__(pint current,
               vector<vector<bool>>& visited,
               queue<pint>& answer) {
    int x = current.first, y = current.second;
    __update__(x - 1, y, visited, answer);
    __update__(x + 1, y, visited, answer);
    __update__(x, y - 1, visited, answer);
    __update__(x, y + 1, visited, answer);
  }

  vector<vector<int>> highestPeak(vector<vector<int>>& input) {
    const int rows = input.size();
    const int cols = input[0].size();

    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    queue<pint> locations;
    queue<pint> next_locations;

    for (int i = 0; i < rows; i++)
      for (int j = 0; j < cols; j++)
        if (input[i][j] == 1) {
          locations.push({i, j});
          visited[i][j] = true;
        }

    int h = 0;
    while (!locations.empty()) {
      pint current = locations.front();
      locations.pop();
      input[current.first][current.second] = h;
      __gen__(current, visited, next_locations);

      if (locations.empty()) {
        locations = next_locations;
        next_locations = queue<pint>();
        h++;
      }
    }

    return input;
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);

  return 0;
}
