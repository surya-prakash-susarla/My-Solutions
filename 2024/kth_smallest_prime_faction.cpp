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
  vector<int> kthSmallestPrimeFraction(vector<int>& values, int k) {
    map<double, pair<int, int>> temp;

    for (int i = 0; i < values.size(); i++)
      for (int j = values.size() - 1; j > i; j--)
        temp[(double)values[i] / (double)values[j]] = {values[i], values[j]};

    auto it = next(temp.begin(), k - 1);
    return it != temp.end() ? vector<int>{it->second.first, it->second.second}
                            : vector<int>{temp.rbegin()->second.first,
                                          temp.rbegin()->second.second};
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
