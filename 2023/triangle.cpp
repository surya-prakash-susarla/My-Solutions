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
  int minimumTotal(vector<vector<int>>& input) {
    vector<int> values = *input.rbegin();
    for (int i = input.size() - 2; i > -1; i--)
      for (int j = 0; j < input[i].size(); j++)
        values[j] = input[i][j] + min(values[j], values[j + 1]);

    return values[0];
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
