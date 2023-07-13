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
  int maxProduct(vector<int>& values) {
    int last_max_value = values[values.size() - 1];
    int last_min_value = values[values.size() - 1];
    int answer = last_min_value;
    for (int i = values.size() - 2; i > -1; i--) {
      int orig_last_min_value = last_min_value;
      last_min_value = min(
          {values[i], values[i] * last_min_value, values[i] * last_max_value});
      last_max_value = max({values[i], values[i] * orig_last_min_value,
                            values[i] * last_max_value});
      answer = max({answer, last_min_value, last_max_value});
    }
    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
