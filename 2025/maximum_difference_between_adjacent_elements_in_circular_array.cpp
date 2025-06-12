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
  int maxAdjacentDistance(vector<int>& input) {
    int answer = INT_MIN;
    for (int i = 1; i < input.size(); i++) {
      answer = max(answer, abs(input[i] - input[i - 1]));
    }
    if (input.size() > 1) {
      answer = max(answer, abs(*input.rbegin() - *input.begin()));
    }
    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
