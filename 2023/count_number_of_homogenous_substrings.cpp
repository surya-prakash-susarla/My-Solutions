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
  static constexpr int modval = 1000000007;

  int get_counts(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
      sum += (n - i + 1);
      sum %= modval;
    }
    return sum;
  }

  int countHomogenous(string s) {
    if (s.empty())
      return 0;
    char c = s[0];
    int count = 1;

    int answer = 0;

    for (int i = 1; i < s.size(); i++) {
      if (s[i] == c) {
        count++;
      } else {
        c = s[i];
        answer += get_counts(count);
        answer %= modval;
        count = 1;
      }
    }

    answer += get_counts(count);
    answer %= modval;

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
