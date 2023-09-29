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
  bool isMonotonic(vector<int>& input) {
    if (input.size() <= 1)
      return true;

    int direction = -1;
    int dir_index = -1;
    for (int i = 1; i < input.size(); i++) {
      if (input[i] < input[i - 1]) {
        dir_index = i;
        direction = 1;
        break;
      } else if (input[i] > input[i - 1]) {
        dir_index = i;
        direction = 0;
        break;
      }
    }

    if (direction == -1)
      return true;

    for (int i = dir_index + 1; i < input.size(); i++) {
      if (input[i] == input[i - 1])
        continue;
      if (input[i] > input[i - 1]) {
        if (direction == 0)
          continue;
        return false;
      } else {
        if (direction == 1)
          continue;
        return false;
      }
    }

    return true;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
