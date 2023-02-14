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
  vector<int> status;
  vector<vector<int>> connections;

  // -1 -> not checked
  // 0 -> midway i.e., failing
  // 1 -> true

  bool __rec__(int index) {
    if (status[index] == 1)
      return true;
    if (status[index] == 0)
      return false;

    status[index] = 0;
    for (int i : connections[index]) {
      bool return_value = __rec__(i);
      if (return_value == false)
        return false;
    }
    status[index] = 1;
    return true;
  }

  bool canFinish(int n, vector<vector<int>>& values) {
    status = vector<int>(n, -1);
    connections = vector<vector<int>>(n, vector<int>());
    for (const vector<int>& i : values) {
      connections[i[0]].push_back(i[1]);
    }
    auto get_next_index = [&]() -> int {
      for (int i = 0; i < n; i++)
        if (status[i] == -1)
          return i;
      return -1;
    };

    int index = get_next_index();
    while (index != -1) {
      bool status = __rec__(index);
      if (status == false)
        return false;
      index = get_next_index();
    }

    return true;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
