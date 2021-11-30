#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#include <vector>

// Problem:

typedef long long int llint;
typedef long double ldouble;

using namespace std;

class Solution {
 public:
  int maxCoins(vector<int>& values) {
    sort(values.begin(), values.end());

    int answer = 0;
    for (int i = values.size() / 3; i < values.size(); i += 2)
      answer += values[i];

    return answer;
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);

  return 0;
}
