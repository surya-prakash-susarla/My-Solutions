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
  int minEatingSpeed(vector<int>& input, int h) {
    typedef long long int llint;
    llint left = 1;
    llint right = *max_element(input.begin(), input.end());

    llint answer = right;

    auto get_time = [](const vector<int>& input, llint k) -> llint {
      llint answer = 0;
      for (llint i : input) {
        if (i % k)
          answer += ((i / k) + 1);
        else
          answer += (i / k);
      }
      return answer;
    };

    while (left <= right) {
      llint current = (left + right) / 2;
      llint timeval = get_time(input, current);

      if (timeval > h) {
        left = current + 1;
      } else if (timeval <= h) {
        answer = min(answer, current);
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
