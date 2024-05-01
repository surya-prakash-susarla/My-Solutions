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
  bool answer = false;

  set<pair<int, int>> memo;

  void __rec__(int index, int left, const string& s) {
    if (left < 0)
      return;
    if (index == s.size()) {
      if (left != 0)
        return;
      answer = true;
    }
    if (answer)
      return;
    if (memo.contains({index, left}))
      return;

    switch (s[index]) {
      case '(':
        return __rec__(index + 1, left + 1, s);
      case ')':
        return __rec__(index + 1, left - 1, s);
      case '*': {
        __rec__(index + 1, left + 1, s);
        __rec__(index + 1, left - 1, s);
        __rec__(index + 1, left, s);
      }
    }

    memo.insert({index, left});
  }

  bool checkValidString(string s) {
    __rec__(0, 0, s);
    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
