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
  vector<int> getSumAbsoluteDifferences(vector<int>& values) {
    const size_t n = values.size();
    vector<int> sums(n);

    int prev_sum = 0;
    for (int i = 0; i < n; i++) {
      prev_sum += values[i];
      sums[i] = prev_sum;
    }

    vector<int> answer(n);
    for (int i = 0; i < n; i++) {
      answer[i] = (i - 1 > -1 ? (i * values[i] - sums[i - 1]) : 0) +
                  ((*sums.rbegin() - sums[i]) - (n - 1 - i) * values[i]);
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
