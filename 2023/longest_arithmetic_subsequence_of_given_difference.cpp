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
  int longestSubsequence(vector<int>& input, int diff) {
    unordered_map<int, int> found;

    int answer = 0;

    for (int i = input.size() - 1; i > -1; i--) {
      found[input[i]] = found[input[i] + diff] + 1;
      answer = max(answer, found[input[i]]);
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
