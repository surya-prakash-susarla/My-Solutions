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
  bool canJump(vector<int>& values) {
    int last_reachable_index = values.size() - 1;

    bool answer = true;

    for (int i = values.size() - 2; i > -1; i--) {
      if (last_reachable_index - i <= values[i]) {
        last_reachable_index = i;
        answer = true;
      } else {
        answer = false;
      }
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
