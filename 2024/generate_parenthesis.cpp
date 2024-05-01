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

  void __rec__(int open, int close, string current) {
    if (open == 0 and close == 0) {
      answer.emplace_back(current);
      return;
    }
    if (open > 0) {
      string temp = current;
      temp += '(';
      __rec__(open - 1, close + 1, temp);
    }
    if (close > 0) {
      string temp = current;
      temp += ')';
      __rec__(open, close - 1, temp);
    }
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
