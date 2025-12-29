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
  int bestClosingTime(string input) {
    int total = 0;

    for (char c : input)
      if (c == 'Y')
        total++;

    int current = 0;

    int min_value = INT_MAX;
    int min_index = -1;

    for (int i = 0; i < input.size(); i++) {
      int rem_open = total - current;
      int closed_days = i - current;

      int pen = rem_open + closed_days;

      if (pen < min_value) {
        min_value = pen;
        min_index = i;
      }

      if (input[i] == 'Y')
        current++;
    }

    if ((int)input.size() - total < min_value) {
      return input.size();
    }

    return min_index;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
