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
  bool is_valid(int i, int j, const vector<vector<int>>& input) {
    int r = input.size();
    int c = input[0].size();

    // cannot form a grid.
    if (r - i < 3 or c - j < 3)
      return false;

    {
      // uniqueness and 1-9 constraint.
      set<int> values;
      for (int x = i; x < i + 3; x++)
        for (int y = j; y < j + 3; y++)
          values.insert(input[x][y]);

      // unique
      if (values.size() < 9)
        return false;

      // 1-9
      for (auto i : values)
        if (i < 1 or i > 9)
          return false;
    }

    vector<int> values;

    // row sums;
    for (int x = i; x < i + 3; x++) {
      int temp = 0;
      for (int y = j; y < j + 3; y++)
        temp += input[x][y];
      values.push_back(temp);
    }

    // col sums;
    for (int y = j; y < j + 3; y++) {
      int temp = 0;
      for (int x = i; x < i + 3; x++)
        temp += input[x][y];
      values.push_back(temp);
    }

    int diag1 = 0;
    for (int x = i, y = j, k = 0; k < 3; x++, y++, k++) {
      diag1 += input[x][y];
    }
    values.push_back(diag1);

    int diag2 = 0;
    for (int x = i, y = j + 2, k = 0; k < 3; x++, y--, k++) {
      diag2 += input[x][y];
    }
    values.push_back(diag2);

    for (int i = 1; i < values.size(); i++)
      if (values[i] != values[i - 1])
        return false;

    return true;
  }

  int numMagicSquaresInside(vector<vector<int>>& input) {
    int count = 0;
    for (int i = 0; i < input.size(); i++) {
      for (int j = 0; j < input[i].size(); j++) {
        if (is_valid(i, j, input))
          count++;
      }
    }
    return count;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
