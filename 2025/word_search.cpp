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
  typedef vector<char> vchar;
  typedef vector<vchar> vvchar;

  bool search(int i, int j, int index, vvchar& values, const string& input) {
    if (index == input.size())
      return true;

    if (i < 0 or j < 0 or i >= values.size() or j >= values[0].size())
      return false;

    if (values[i][j] != input[index])
      return false;

    int orig_char = values[i][j];
    values[i][j] = '@';

    bool result = false;
    result |= search(i + 1, j, index + 1, values, input);
    result |= search(i - 1, j, index + 1, values, input);
    result |= search(i, j + 1, index + 1, values, input);
    result |= search(i, j - 1, index + 1, values, input);

    values[i][j] = orig_char;

    return result;
  }

  bool exist(vector<vector<char>>& values, string input) {
    for (int i = 0; i < values.size(); i++) {
      for (int j = 0; j < values[0].size(); j++) {
        if (search(i, j, 0, values, input))
          return true;
      }
    }
    return false;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
