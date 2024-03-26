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
  int firstMissingPositive(vector<int>& values) {
    set<int> temp;
    for (int i : values)
      if (i > 0)
        temp.insert(i);

    if (temp.size() == 0 or *temp.begin() > 1)
      return 1;

    for (auto it = next(temp.begin()); it != temp.end(); it = next(it)) {
      auto it2 = prev(it);
      if (*it - *it2 > 1)
        return *it2 + 1;
    }

    return *temp.rbegin() + 1;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
