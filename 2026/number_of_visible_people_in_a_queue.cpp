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
  vector<int> canSeePersonsCount(vector<int>& input) {
    vector<int> answer(input.size());
    stack<int> values;

    for (int i = input.size() - 1; i > -1; i--) {
      int current = input[i];
      int seen = 0;

      while (not values.empty() and values.top() < current) {
        values.pop();
        seen++;
      }

      if (not values.empty()) {
        seen++;
      }

      answer[i] = seen;
      values.push(input[i]);
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
