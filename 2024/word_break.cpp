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
  unordered_set<string> dict;
  vector<int> memo;

  bool is_splittable(int index, const string& input) {
    if (index == input.size())
      return true;
    if (memo[index] != -1)
      return (bool)(memo[index]);
    for (int i = index; i < input.size(); i++) {
      string prefix_segment = input.substr(index, i - index + 1);
      if (dict.contains(prefix_segment) and is_splittable(i + 1, input)) {
        memo[index] = 1;
        return true;
      }
    }
    memo[index] = 0;
    return false;
  }

  bool wordBreak(string s, vector<string>& wordDict) {
    dict = unordered_set<string>(wordDict.begin(), wordDict.end());
    memo = vector<int>(s.size(), -1);

    return is_splittable(0, s);
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
