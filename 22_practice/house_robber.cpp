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
    if (values.size() <= 2)
      return *max_element(values.begin(), values.end());

    int n = values.size();
    values[n - 2] = max(values[n - 2], values[n - 1]);
    int answer = numeric_limits<int>::min();
    for (int i = n - 3; i > -1; i--) {
      values[i] = max(values[i + 1], values[i] + values[i + 2]);
      answer = max(answer, values[i]);
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
