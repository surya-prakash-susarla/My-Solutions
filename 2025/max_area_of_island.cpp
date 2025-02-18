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
  typedef vector<int> vint;
  typedef vector<vint> vvint;

  vvint input;

  void cover(int i, int j, int& value) {
    if (i < 0 or j < 0 or i >= input.size() or j >= input[0].size())
      return;

    if (input[i][j] == 0)
      return;

    value++;
    input[i][j] = 0;

    cover(i - 1, j, value);
    cover(i + 1, j, value);
    cover(i, j - 1, value);
    cover(i, j + 1, value);
  }

  int maxAreaOfIsland(vector<vector<int>>& grid) {
    int answer = 0;

    input = grid;

    for (int i = 0; i < input.size(); i++) {
      for (int j = 0; j < input[0].size(); j++) {
        if (input[i][j] == 1) {
          int current = 0;
          cover(i, j, current);
          answer = max(answer, current);
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
