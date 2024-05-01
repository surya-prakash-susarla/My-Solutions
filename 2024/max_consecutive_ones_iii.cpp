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
  int get(int index,
          int k,
          const vector<int>& values,
          const vector<int>& type) {
    if (index == values.size())
      return 0;

    int answer = -1;
    if (type[index] == 1) {
      answer = values[index] + get(index + 1, k, values, type);
    } else {
      if (k < values[index]) {
        answer = min(values[index], k);
      } else {
        answer =
            values[index] + get(index + 1, k - values[index], values, type);
      }
    }

    return answer;
  }

  int longestOnes(vector<int>& nums, int k) {
    vector<int> values;
    vector<int> type;

    int prev_type = nums[0];
    int prev_count = 1;

    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] == prev_type) {
        prev_count++;
      } else {
        values.push_back(prev_count);
        type.push_back(prev_type);
        prev_type = nums[i];
        prev_count = 1;
      }
    }

    values.push_back(prev_count);
    type.push_back(prev_type);

    int answer = INT_MIN;
    for (int i = 0; i < type.size(); i++) {
      if (type[i] == 1) {
        int current = get(i, k, values, type);
        answer = max(answer, current);
      } else {
        for (int j = 1; j <= min(values[i], k); j++) {
          int current = j + get(i + 1, k - j, values, type);
          answer = max(answer, current);
        }
      }
    }

    return answer == INT_MIN ? 0 : answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
