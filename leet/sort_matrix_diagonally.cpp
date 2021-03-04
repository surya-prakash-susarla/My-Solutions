#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#include <vector>


// Problem: https://leetcode.com/problems/sort-the-matrix-diagonally/

typedef long long int llint;
typedef long double ldouble;

using namespace std;

class Solution {
 public:
  vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
    using pint = pair<int, int>;
    vector<pint> pts;
    pts.push_back({0, 0});
    for (int i = 1; i < mat.size(); i++)
      pts.push_back({i, 0});
    for (int i = 1; i < mat[0].size(); i++)
      pts.push_back({0, i});
    const int row = mat.size();
    const int col = mat[0].size();
    for (const pint& i : pts) {
      vector<int> temp;
      for (int j = i.first, k = i.second; j < row and k < col; j++, k++)
        temp.push_back(mat[j][k]);
      sort(temp.begin(), temp.end());
      for (int j = i.first, k = i.second, l = 0; j < row and k < col;
           j++, k++, l++)
        mat[j][k] = temp[l];
    }
    return mat;
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);

  return 0;
}
