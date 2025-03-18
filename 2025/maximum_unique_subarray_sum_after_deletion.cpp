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
  int maxSum(vector<int>& input) {
    unordered_set<int> values;
    int min_value = INT_MIN;
    int answer = 0;
    for (int i : input) {
      if (i > 0) {
        if (not values.contains(i)) {
          values.insert(i);
          answer += i;
        }
      } else {
        min_value = max(min_value, i);
      }
    }

    return values.empty() ? min_value : answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
