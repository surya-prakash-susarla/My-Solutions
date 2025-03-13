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
  typedef vector<int> vint;
  typedef vector<vint> vvint;

  bool is_valid(const vint& values, const vvint& input, int k) {
    vint temp(values.size());
    for (int i = 0; i < k; i++) {
      int start = input[i][0];
      int end = input[i][1];
      int val = input[i][2];
      temp[start] += val;
      if (end + 1 < values.size())
        temp[end + 1] -= val;
    }
    int current = 0;
    for (int i = 0; i < values.size(); i++) {
      current += temp[i];
      if (current < values[i])
        return false;
    }
    return true;
  }

  int minZeroArray(vector<int>& values, vector<vector<int>>& input) {
    int left = 0;
    int right = input.size();

    int answer = INT_MAX;
    while (left <= right) {
      const int current = (left + right) / 2;
      if (is_valid(values, input, current)) {
        answer = min(answer, current);
        right = current - 1;
      } else {
        left = current + 1;
      }
    }

    return answer == INT_MAX ? -1 : answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
