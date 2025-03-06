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
  vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
    int a, n = grid.size();
    vector<int> num_freq(n * n + 1, 0);
    for (vector<int> row : grid) {
      for (int num : row) {
        if (num_freq[num] == 1)
          a = num;
        num_freq[num]++;
      }
    }
    for (int num = 1; num <= n * n; num++)
      if (num_freq[num] == 0)
        return {a, num};
    return {-1, -1};
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
