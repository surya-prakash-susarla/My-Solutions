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
  string input;

  map<tuple<int, int, int>, bool> memo;

  bool is_valid(int i, int j, int k) {
    if (i > j)
      return true;

    if (k < 0)
      return false;

    tuple<int, int, int> current = make_tuple(i, j, k);
    auto it = memo.find(current);
    if (it != memo.end())
      return it->second;

    bool answer = false;
    if (input[i] == input[j]) {
      answer = is_valid(i + 1, j - 1, k);
    } else {
      answer = is_valid(i + 1, j, k - 1) or is_valid(i, j - 1, k - 1);
    }

    memo[current] = answer;
    return answer;
  }

  bool isValidPalindrome(string s, int k) {
    input = s;
    return is_valid(0, s.size() - 1, k);
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
