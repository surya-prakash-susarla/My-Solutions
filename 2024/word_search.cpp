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
  bool __rec__(int i,
               int j,
               int ii,
               vector<vector<char>>& values,
               const string& input) {
    if (ii >= input.size())
      return true;

    if (i < 0 or j < 0 or i >= values.size() or j >= values[0].size())
      return false;

    if (values[i][j] == '@' or values[i][j] != input[ii])
      return false;

    ii++;
    const char orig = values[i][j];
    values[i][j] = '@';

    bool result = __rec__(i + 1, j, ii, values, input) or
                  __rec__(i, j + 1, ii, values, input) or
                  __rec__(i - 1, j, ii, values, input) or
                  __rec__(i, j - 1, ii, values, input);

    values[i][j] = orig;

    return result;
  }

  bool exist(vector<vector<char>>& values, string input) {
    for (int i = 0; i < values.size(); i++)
      for (int j = 0; j < values[0].size(); j++)
        if (__rec__(i, j, 0, values, input))
          return true;
    return false;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
