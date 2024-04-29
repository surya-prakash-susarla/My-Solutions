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
  string longestCommonPrefix(vector<string>& values) {
    int maxsize = INT_MAX;
    for (auto i : values)
      maxsize = min(maxsize, (int)i.size());

    int ind = 0;
    bool break_found = false;
    while (ind < maxsize and not break_found) {
      char base = values[0][ind];
      for (int i = 1; i < values.size(); i++)
        if (values[i][ind] != base) {
          break_found = true;
          break;
        }
      if (not break_found)
        ind++;
    }

    return values[0].substr(0, ind);
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
