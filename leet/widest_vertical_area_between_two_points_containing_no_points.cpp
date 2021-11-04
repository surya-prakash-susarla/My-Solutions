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
  int maxWidthOfVerticalArea(vector<vector<int>>& input) {
    sort(
        input.begin(), input.end(),
        [](const vector<int>& a, const vector<int>& b) { return a[0] < b[0]; });

    int answer = 0;
    for (int i = 1; i < input.size(); i++) {
      answer = max(answer, input[i][0] - input[i - 1][0]);
    }

    return answer;
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);

  return 0;
}
