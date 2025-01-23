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
  int countServers(vector<vector<int>>& input) {
    typedef pair<int, int> pint;

    set<pint> locations;

    const int m = input.size();
    const int n = input[0].size();

    // check row wise.
    for (int i = 0; i < m; i++) {
      set<pint> temp;
      for (int j = 0; j < n; j++) {
        if (input[i][j] == 1) {
          temp.insert({i, j});
        }
      }
      if (temp.size() > 1) {
        locations.insert(temp.begin(), temp.end());
      }
    }

    // check col wise.
    for (int j = 0; j < n; j++) {
      set<pint> temp;
      for (int i = 0; i < m; i++) {
        if (input[i][j] == 1) {
          temp.insert({i, j});
        }
      }
      if (temp.size() > 1) {
        locations.insert(temp.begin(), temp.end());
      }
    }

    return locations.size();
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
