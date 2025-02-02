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
  bool check(vector<int>& input) {
    bool break_found = false;
    const int pre_break_min = input[0];

    for (int i = 1; i < input.size(); i++) {
      if (break_found) {
        if (input[i] < input[i - 1] or input[i] > pre_break_min)
          return false;
      } else if (input[i] < input[i - 1]) {
        break_found = true;
        if (input[i] > pre_break_min)
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
