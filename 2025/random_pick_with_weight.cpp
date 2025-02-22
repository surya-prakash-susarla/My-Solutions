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
  map<int, int> sum_values;
  int total = 0;

  Solution(vector<int>& input) {
    for (int i = 0; i < input.size(); i++) {
      total += input[i];
      sum_values[total] = i;
    }
  }

  int randomValue() { return rand() % total; }

  int pickIndex() { return sum_values.upper_bound(randomValue())->second; }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
