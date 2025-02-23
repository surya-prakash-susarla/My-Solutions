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
  vector<int> findClosestElements(vector<int>& input, int k, int x) {
    int right = lower_bound(input.begin(), input.end(), x) - input.begin();
    int left = right - 1;

    typedef vector<int> vint;

    auto get_value = [&](int ind) -> int {
      if (ind >= input.size() or ind < 0)
        return INT_MAX;
      return abs(input[ind] - x);
    };

    deque<int> answer;
    while (answer.size() < k) {
      int left_value = get_value(left);
      int right_value = get_value(right);

      if (left_value <= right_value) {
        answer.push_front(input[left]);
        left--;
      } else {
        answer.push_back(input[right]);
        right++;
      }
    }

    vector<int> final_answer;
    for (int i : answer)
      final_answer.push_back(i);

    return final_answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
