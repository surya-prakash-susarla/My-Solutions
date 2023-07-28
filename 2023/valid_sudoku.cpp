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
  typedef vector<bool> vbool;

  inline optional<char> inp(char c) {
    if (c == '.')
      return nullopt;
    return c - '0';
  }

  bool isValidSudoku(vector<vector<char>>& input) {
    // check if there are duplicates in a row.
    for (int i = 0; i < 9; i++) {
      vbool covered(10, false);
      for (int j = 0; j < 9; j++) {
        optional<int> value = inp(input[i][j]);
        if (value) {
          if (not covered[*value])
            covered[*value] = true;
          else
            return false;
        }
      }
    }

    // check if there are duplicates in a column.
    for (int j = 0; j < 9; j++) {
      vbool covered(10, false);
      for (int i = 0; i < 9; i++) {
        optional<int> value = inp(input[i][j]);
        if (value) {
          if (not covered[*value])
            covered[*value] = true;
          else
            return false;
        }
      }
    }

    auto _val = [&](int is, int js) -> bool {
      vbool covered(10, false);
      for (int i = is; i < is + 3; i++) {
        for (int j = js; j < js + 3; j++) {
          optional<int> value = inp(input[i][j]);
          if (value) {
            if (not covered[*value])
              covered[*value] = true;
            else
              return false;
          }
        }
      }
      return true;
    };

    // check for 3x3 sub-plots.
    for (int i = 0; i < 9; i += 3) {
      for (int j = 0; j < 9; j += 3) {
        bool response = _val(i, j);
        if (not response)
          return false;
      }
    }

    return true;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
