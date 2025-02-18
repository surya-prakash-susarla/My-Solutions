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
  bool walk(int ind, vector<int>& taken, map<int, vector<int>>& deps) {
    // cout << "current index : " << ind << endl;
    if (taken[ind] == 1) {
      // cout << "return false since taken" << endl;
      return false;
    }
    if (taken[ind] == 2)
      return true;

    taken[ind] = 1;

    for (int i : deps[ind])
      if (not walk(i, taken, deps))
        return false;

    taken[ind] = 2;

    return true;
  }

  bool canFinish(int n, vector<vector<int>>& input) {
    vector<int> taken(n, 0);

    map<int, vector<int>> deps;
    for (auto i : input)
      deps[i[0]].push_back(i[1]);

    while (true) {
      int ind = -1;
      for (int i = 0; i < n; i++)
        if (taken[i] == 0) {
          ind = i;
          break;
        }

      if (ind == -1) {
        break;
      }

      // cout << "chosen index : " << ind << endl;

      if (not walk(ind, taken, deps))
        return false;
    }

    for (int i : taken)
      if (i == 1)
        return false;

    return true;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
