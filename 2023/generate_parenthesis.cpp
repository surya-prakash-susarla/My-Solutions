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
  vector<string> answer;

  void __rec__(int n, int r, string c) {
    if (n == 0 and r == 0)
      answer.emplace_back(c);

    if (r > 0)
      __rec__(n, r - 1, c + ")");
    if (n > 0)
      __rec__(n - 1, r + 1, c + "(");
  }

  vector<string> generateParenthesis(int n) {
    __rec__(n, 0, "");
    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
