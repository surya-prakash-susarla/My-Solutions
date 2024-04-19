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

  optional<pair<int, int>> find(const vvchar& values) {
    for (int i = 0; i < values.size(); i++)
      for (int j = 0; j < values[i].size(); j++)
        if (values[i][j] == '1')
          return make_pair(i, j);
    return nullopt;
  }

  void __rec__(int i, int j, vvchar& values) {
    if (i < 0 or j < 0 or i >= values.size() or j >= values[i].size())
      return;
    if (values[i][j] == '0')
      return;
    values[i][j] = '0';
    __rec__(i - 1, j, values);
    __rec__(i, j - 1, values);
    __rec__(i + 1, j, values);
    __rec__(i, j + 1, values);
    return;
  }

  int numIslands(vector<vector<char>>& input) {
    int answer = 0;
    while (true) {
      optional<pair<int, int>> loc = find(input);
      if (not loc.has_value())
        break;
      __rec__(loc->first, loc->second, input);
      answer++;
    }
    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
