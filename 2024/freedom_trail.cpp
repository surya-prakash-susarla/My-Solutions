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
  vector<vector<int>> memo;

  inline int getMinDist(int ri, int di, int n) {
    const int i = min(ri, di);
    const int j = max(ri, di);
    return min(j - i, i + n - j);
  }

  int findSteps(int ri,
                int ki,
                const int rs,
                const string key,
                const map<char, vector<int>>& ind) {
    if (ki == key.size())
      return 0;

    if (memo[ri][ki] != -1)
      return memo[ri][ki];

    int answer = INT_MAX;
    for (int i : ind.find(key[ki])->second)
      answer = min(answer, getMinDist(ri, i, rs) +
                               findSteps(i, ki + 1, rs, key, ind) + 1);

    memo[ri][ki] = answer;

    return answer;
  }

  int findRotateSteps(string ring, string key) {
    map<char, vector<int>> ind;
    for (int i = 0; i < ring.size(); i++)
      ind[ring[i]].push_back(i);

    memo = vector<vector<int>>(ring.size(), vector<int>(key.size(), -1));

    return findSteps(0, 0, ring.size(), key, ind);
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
