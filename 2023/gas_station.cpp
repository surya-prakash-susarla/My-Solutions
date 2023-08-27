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
  bool is_valid(int orig, const vint& values) {
    int temp = values[orig];
    if (temp < 0)
      return false;
    const int n = values.size();
    for (int i = (orig + 1) % n; i != orig; i = (i + 1) % n) {
      temp += values[i];
      if (temp < 0)
        return false;
    }
    return true;
  }

  int canCompleteCircuit(vector<int>& g, vector<int>& c) {
    vint d;
    map<int, int> ind;
    for (int i = 0; i < g.size(); i++) {
      int del = g[i] - c[i];
      if (del != 0 or d.size() == 0 or *d.rbegin() != 0) {
        d.push_back(del);
        ind[d.size() - 1] = i;
      }
    }

    for (int i = 0; i < d.size(); i++) {
      if (is_valid(i, d))
        return ind[i];
    }
    return -1;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
