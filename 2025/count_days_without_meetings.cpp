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
  bool is_overlap(int prev_end, int start, int end) {
    return prev_end >= start;
  }

  int countDays(int n, vector<vector<int>>& input) {
    if (input.size() == 0)
      return n;

    sort(input.begin(), input.end(),
         [](const vector<int>& a, const vector<int>& b) {
           if (a[0] == b[0])
             return a[1] < b[1];
           return a[0] < b[0];
         });

    int prev_end = input[0][1];
    int answer = input[0][0] - 1;
    int last_interval = 0;

    for (int i = 1; i < input.size(); i++) {
      if (input[i][0] > n) {
        break;
      }
      if (is_overlap(prev_end, input[i][0], input[i][1])) {
        if (input[i][1] > prev_end) {
          prev_end = input[i][1];
          last_interval = i;
        }
      } else {
        answer += (input[i][0] - prev_end - 1);
        prev_end = input[i][1];
        last_interval = i;
      }
    }

    if (n > input[last_interval][1]) {
      answer += (n - input[last_interval][1]);
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
