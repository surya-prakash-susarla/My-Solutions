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
  int rob(vector<int>& values) {
    const int n = values.size();
    vector<int> memo(values.size());
    memo[n - 1] = values[n - 1];

    int answer = memo[n - 1];

    for (int i = n - 2; i > -1; i--) {
      int incl_value = values[i];
      if (i + 2 < n) {
        incl_value += memo[i + 2];
      }

      memo[i] = max(incl_value, memo[i + 1]);
      answer = max(answer, memo[i]);
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
