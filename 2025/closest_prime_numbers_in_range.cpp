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
  vector<int> closestPrimes(int left, int right) {
    vector<int> values(right + 1, -1);

    for (int i = 2; i <= right; i++) {
      if (values[i] == 2)
        continue;

      values[i] = 1;

      for (int j = 2; j * i <= right; j++)
        values[j * i] = 2;
    }

    int prev = -1;
    int prev_diff = INT_MAX;
    vector<int> answer;

    left = (left == 1) ? 2 : left;

    for (int i = left; i <= right; i++) {
      if (values[i] == 2)
        continue;

      if (prev != -1) {
        int cdiff = i - prev;
        if (cdiff < prev_diff) {
          prev_diff = cdiff;
          answer = {prev, i};
        }
      }

      prev = i;
    }

    return answer.empty() ? vector<int>({-1, -1}) : answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
