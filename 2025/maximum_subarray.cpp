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
  int maxSubArray(vector<int>& input) {
    vector<int> values(input.size());

    values[input.size() - 1] = *input.rbegin();

    int answer = *input.rbegin();

    for (int i = input.size() - 2; i > -1; i--) {
      values[i] = max(input[i], input[i] + values[i + 1]);
      answer = max(answer, values[i]);
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
