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
  unordered_map<int, vector<int>> values;

  Solution(vector<int>& input) {
    for (int i = 0; i < input.size(); i++)
      values[input[i]].push_back(i);
  }

  int randomValue(const int maxval) { return rand() % maxval; }

  int pick(int target) {
    auto it = values.find(target);
    return it->second[randomValue(it->second.size())];
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
