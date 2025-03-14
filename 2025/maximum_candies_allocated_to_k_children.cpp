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
  int maximumCandies(vector<int>& input, long long k) {
    auto is_valid = [&](int x) -> bool {
      if (x == 0)
        return true;
      long long counter = 0;
      for (int i : input) {
        counter += (i / x);
        if (counter >= k)
          return true;
      }
      return false;
    };

    int left = 0;
    int right = *max_element(input.begin(), input.end());
    int answer = left;
    while (left <= right) {
      int current = (left + right) / 2;
      if (is_valid(current)) {
        answer = max(answer, current);
        left = current + 1;
      } else {
        right = current - 1;
      }
    }
    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
