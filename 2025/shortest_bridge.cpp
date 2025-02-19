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
  typedef pair<int, int> pint;
  typedef vector<pair<int, int>> vpint;
  typedef vector<vector<int>> vvint;

  bool is_boundary(int i, int j, const vvint& input) {
    if (i - 1 > -1 and input[i - 1][j] == 0)
      return true;
    if (i + 1 < input.size() and input[i + 1][j] == 0)
      return true;
    if (j - 1 > -1 and input[i][j - 1] == 0)
      return true;
    if (j + 1 < input.size() and input[i][j + 1] == 0)
      return true;
    return false;
  }

  void trav(int i, int j, vpint& boundaries, vvint& input) {
    if (i < 0 or j < 0 or i >= input.size() or j >= input.size())
      return;

    if (input[i][j] != 1)
      return;

    input[i][j] = 2;
    if (is_boundary(i, j, input)) {
      boundaries.emplace_back(make_pair(i, j));
    }

    trav(i + 1, j, boundaries, input);
    trav(i - 1, j, boundaries, input);
    trav(i, j - 1, boundaries, input);
    trav(i, j + 1, boundaries, input);
  }

  int shortestBridge(vector<vector<int>>& input) {
    vpint first_island_boundary;
    vpint second_island_boundary;

    bool first_island_found = false;
    for (int i = 0; i < input.size(); i++) {
      for (int j = 0; j < input.size(); j++) {
        if (input[i][j] == 1) {
          if (first_island_found) {
            trav(i, j, second_island_boundary, input);
          } else {
            first_island_found = true;
            trav(i, j, first_island_boundary, input);
          }
        }
      }
    }

    // cout << "First island boundaries : " << endl;
    // for ( auto i : first_island_boundary )  cout << i.first << "," <<
    // i.second << endl; cout << endl << "Second island boundaries : " << endl;
    // for ( auto i : second_island_boundary ) cout << i.first << "," <<
    // i.second << endl;

    auto dist = [](const pint& a, const pint& b) -> int {
      return abs(a.first - b.first) + abs(a.second - b.second) - 1;
    };

    int mindist = INT_MAX;
    for (auto i : first_island_boundary) {
      for (auto j : second_island_boundary) {
        mindist = min(mindist, dist(i, j));
      }
    }

    return mindist;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
