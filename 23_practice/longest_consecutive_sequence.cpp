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
  int longestConsecutive(vector<int>& input) {
    if (input.empty())
      return 0;

    set<int> values;
    for (int i : input)
      values.insert(i);

    int answer = 0;
    int cc = 1;

    for (auto it = next(values.begin(), 1); it != values.end();
         it = next(it, 1)) {
      if (*it - *next(it, -1) == 1) {
        cc++;
      } else {
        answer = max(answer, cc);
        cc = 1;
      }
    }

    answer = max(answer, cc);

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
