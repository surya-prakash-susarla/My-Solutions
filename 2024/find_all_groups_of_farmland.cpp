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
  vector<int> setGrid(int ti, int tj, vector<vector<int>>& land) {
    int col = land[ti].size() - 1;
    for (int k = tj + 1; k < land[ti].size(); k++)
      if (land[ti][k] == 0) {
        col = k - 1;
        break;
      }

    int row = land.size() - 1;
    for (int k = ti + 1; k < land.size(); k++)
      if (land[k][tj] == 0) {
        row = k - 1;
        break;
      }

    for (int i = ti; i <= row; i++)
      for (int j = tj; j <= col; j++)
        land[i][j] = 0;

    return {ti, tj, row, col};
  }

  vector<vector<int>> findFarmland(vector<vector<int>>& land) {
    vector<vector<int>> answer;
    for (int i = 0; i < land.size(); i++)
      for (int j = 0; j < land[i].size(); j++)
        if (land[i][j] == 1)
          answer.emplace_back(setGrid(i, j, land));
    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
