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

  void fill(int& init, int rs, int cs, int re, int ce, vvint& ref) {
    for (int j = cs; j < ce; j++)
      ref[rs][j] = init++;

    for (int i = rs; i < re; i++)
      ref[i][ce] = init++;

    for (int j = ce; j > cs; j--)
      ref[re][j] = init++;

    for (int i = re; i > rs; i--)
      ref[i][cs] = init++;
  }

  vector<vector<int>> generateMatrix(int n) {
    vvint answer(n, vint(n));

    int value = 1;
    int rs = 0;
    int cs = 0;
    int re = n - 1;
    int ce = n - 1;
    for (int i = 1; i < n; i++)
      fill(value, rs++, cs++, re--, ce--, answer);

    if (n % 2)
      answer[n / 2][n / 2] = n * n;

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
