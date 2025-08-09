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
  vector<int> twoSum(vector<int>& input, int target) {
    unordered_map<int, int> values;
    for (int i = 0; i < input.size(); i++) {
      values[input[i]] = i;
    }

    for (int i = 0; i < input.size(); i++) {
      auto it = values.find(target - input[i]);
      if (it != values.end() and it->second != i) {
        return {i, it->second};
      }
    }

    return {};
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
