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
  int minDifference(vector<int>& input) {
    if (input.size() <= 4)
      return 0;

    sort(input.begin(), input.end());

    const int k = input.size() - 3;
    int answer = INT_MAX;

    for (int i = 0; i <= input.size() - k; i++)
      answer = min(answer, abs(input[i + k - 1] - input[i]));

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
