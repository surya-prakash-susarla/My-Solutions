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
  long long maximumSubarraySum(vector<int>& values, int k) {
    // find all duplicate locations.
    vector<int> dups(values.size(), -1);
    {
      map<int, int> temp;
      for (int i = 0; i < values.size(); i++) {
        auto it = temp.find(values[i]);
        if (it != temp.end()) {
          dups[i] = it->second;
          it->second = i;
        } else {
          temp[values[i]] = i;
        }
      }
    }

    int past_conflict_index = 0;
    long long answer = 0;
    long long csum = 0;
    for (int i = 0; i <= values.size() - k; i++) {
      if (i > 0)
        csum -= values[i - 1];
      if (past_conflict_index != -1) {
        int break_found_at = -1;
        for (int j = past_conflict_index; j < i + k; j++) {
          if (dups[j] >= i and i != j) {
            break_found_at = j;
            break;
          } else {
            csum += values[j];
          }
        }
        if (break_found_at != -1) {
          past_conflict_index = break_found_at;
        } else {
          answer = max(answer, csum);
          past_conflict_index = -1;
        }
      } else {
        int ni = i + k - 1;
        if (dups[ni] >= i) {
          past_conflict_index = ni;
        } else {
          csum += values[ni];
          answer = max(answer, csum);
        }
      }
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
