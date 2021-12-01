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

// Problem:

typedef long long int llint;
typedef long double ldouble;

using namespace std;

class Solution {
 public:
  vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
    using vint = vector<int>;
    vint parents(n, -1);

    for (const vint& i : edges)
      parents[i[1]] = parents[i[0]] == -1 ? i[0] : parents[i[0]];

    vint answer;
    for (int i = 0; i < n; i++)
      if (parents[i] == -1)
        answer.push_back(i);

    return answer;
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);

  return 0;
}
