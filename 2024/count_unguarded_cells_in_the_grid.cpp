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
  int countUnguarded(int m,
                     int n,
                     vector<vector<int>>& guards,
                     vector<vector<int>>& walls) {
    int answer = 0;

    map<int, map<int, char>> row_map;
    map<int, map<int, char>> col_map;

    for (const vector<int>& i : walls) {
      row_map[i[0]][i[1]] = 'w';
      col_map[i[1]][i[0]] = 'w';
    }

    for (const vector<int>& i : guards) {
      row_map[i[0]][i[1]] = 'g';
      col_map[i[1]][i[0]] = 'g';
    }

    auto get_chars_using_bounds = [](const map<int, char>& target,
                                     const int index) -> pair<char, char> {
      auto bound_value = target.lower_bound(index);
      pair<char, char> answer;
      if (bound_value == target.end()) {
        return {target.rbegin()->second, 'w'};
      } else if (bound_value->first == index) {
        return {'g', 'g'};
      } else if (bound_value == target.begin()) {
        return {'w', bound_value->second};
      } else {
        auto lesser_value = prev(bound_value);
        return {lesser_value->second, bound_value->second};
      }
    };

    auto find_row_maps = [&](const int row, const int col) -> pair<char, char> {
      auto it = row_map.find(row);
      if (it == row_map.end())
        return {'w', 'w'};
      return get_chars_using_bounds(it->second, col);
    };

    auto find_col_maps = [&](const int row, const int col) -> pair<char, char> {
      auto it = col_map.find(col);
      if (it == col_map.end())
        return {'w', 'w'};
      return get_chars_using_bounds(it->second, row);
    };

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        const pair<char, char> row_result = find_row_maps(i, j);
        const pair<char, char> col_result = find_col_maps(i, j);

        const char left = row_result.first;
        const char right = row_result.second;
        const char top = col_result.first;
        const char bottom = col_result.second;

        if (left == 'g' or right == 'g' or top == 'g' or bottom == 'g') {
          // this cell is ineligible.
        } else {
          // cout << "incrementing for location : " << i << " , " << j << endl;
          answer++;
        }
      }
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
