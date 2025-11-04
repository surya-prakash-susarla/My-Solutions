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
  int minCost(string input, vector<int>& times) {
    int answer = 0;
    for (int i = 0; i < input.size() - 1;) {
      if (input[i] == input[i + 1]) {
        // duplicate found.
        int total_sum = times[i];
        int max_value = times[i];
        int j = -1;
        for (j = i + 1; j < input.size(); j++) {
          if (input[j] == input[i]) {
            max_value = max(max_value, times[j]);
            total_sum += times[j];
          } else {
            break;
          }
        }
        total_sum -= max_value;
        answer += total_sum;
        i = j;
      } else {
        // no duplicate.
        i++;
      }
    }
    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
