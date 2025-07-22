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
  int maximumUniqueSubarray(vector<int>& input) {
    int current = 0;
    int answer = 0;
    int oldest_index = INT_MAX;

    unordered_map<int, int> values;

    for (int i = 0; i < input.size(); i++) {
      if (values.contains(input[i])) {
        int dest_ind = values[input[i]];

        for (int k = oldest_index; k <= dest_ind; k++) {
          values.erase(input[k]);
          current -= input[k];
        }

        oldest_index = (dest_ind + 1 == i) ? INT_MAX : dest_ind + 1;
      }

      oldest_index = min(oldest_index, i);

      values[input[i]] = i;
      current += input[i];
      answer = max(answer, current);
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
