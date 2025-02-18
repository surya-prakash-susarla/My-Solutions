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
  int search(int start, int end, const vector<int>& input, const int target) {
    if (start > end)
      return -1;

    int n = (start + end) / 2;
    if (input[n] == target)
      return n;
    else if (input[n] < target)
      return search(n + 1, end, input, target);
    return search(start, n - 1, input, target);
  }

  vector<int> twoSum(vector<int>& input, int target) {
    vector<int> answer;
    for (int i = 0; i < input.size(); i++) {
      if (target - input[i] < input[i])
        continue;

      int result = search(i + 1, input.size() - 1, input, target - input[i]);
      if (result != -1)
        return {i + 1, result + 1};
    }

    return {-1, -1};
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
