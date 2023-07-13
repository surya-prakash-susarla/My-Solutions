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
  int count = 0;

  void __rec__(vector<vector<char>>& values, int i, int j) {
    if (i < 0 or i == values.size() or j < 0 or j == values[0].size())
      return;

    if (values[i][j] == '0')
      return;

    // cout << "at location : " << i << " " << j << endl;

    values[i][j] = '0';
    __rec__(values, i - 1, j);
    __rec__(values, i + 1, j);
    __rec__(values, i, j - 1);
    __rec__(values, i, j + 1);

    return;
  }

  void __run__(vector<vector<char>>& values) {
    auto find_loc = [&]() -> optional<pair<int, int>> {
      for (int i = 0; i < values.size(); i++)
        for (int j = 0; j < values[i].size(); j++)
          if (values[i][j] == '1')
            return make_pair(i, j);
      return nullopt;
    };

    optional<pair<int, int>> temp = find_loc();
    while (temp.has_value()) {
      // cout << "running at location : " << temp->first << " " << temp->second
      // << endl;
      count++;
      __rec__(values, temp->first, temp->second);

      temp = find_loc();
    }
    // cout << "iterations complete" << endl;
  }

  int numIslands(vector<vector<char>>& grid) {
    __run__(grid);
    return count;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
