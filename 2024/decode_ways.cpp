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
  vector<int> values;

  int __rec__(int index, const string& s) {
    if (index == s.size()) {
      return 1;
    }
    if (index > s.size()) {
      return 0;
    }

    if (values[index] != -1)
      return values[index];

    if (s[index] == '0')
      return 0;

    int answer = 0;

    // include only this one.
    answer += __rec__(index + 1, s);

    // include this and the next if possible.
    if (s[index] == '1') {
      answer += __rec__(index + 2, s);
    } else if (s[index] == '2') {
      if (index + 1 < s.size() and s[index + 1] <= '6')
        answer += __rec__(index + 2, s);
    }

    values[index] = answer;

    return answer;
  }

  int numDecodings(string s) {
    values = vector<int>(s.size(), -1);
    return __rec__(0, s);
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
