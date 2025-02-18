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
  typedef vector<char> vint;
  typedef vector<vint> vvint;

  void walk(int i, int j, vvint& values) {
    if (i < 0 or j < 0 or i >= values.size() or j >= values[0].size())
      return;

    if (values[i][j] == '0')
      return;

    values[i][j] = '0';

    walk(i + 1, j, values);
    walk(i - 1, j, values);
    walk(i, j + 1, values);
    walk(i, j - 1, values);
  }

  int numIslands(vector<vector<char>>& input) {
    int answer = 0;

    for (int i = 0; i < input.size(); i++) {
      for (int j = 0; j < input[0].size(); j++) {
        if (input[i][j] == '1') {
          answer++;
          walk(i, j, input);
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
