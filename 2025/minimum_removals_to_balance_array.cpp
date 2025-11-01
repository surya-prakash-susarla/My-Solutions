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
  int minRemoval(vector<int>& input, int k) {
    if (input.size() == 1)
      return 0;

    sort(input.begin(), input.end());

    int answer = INT_MAX;

    for (int i = 0; i < input.size(); i++) {
      int cut_left = i;

      int cut_right = 0;
      {
        auto it = upper_bound(input.begin() + i, input.end(),
                              (long long)input[i] * k);
        if (it != input.end())
          cut_right = distance(it, input.end());
      }

      answer = min(answer, cut_left + cut_right);
      if (cut_right == 0)
        break;
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
