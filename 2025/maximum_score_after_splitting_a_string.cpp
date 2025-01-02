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
  int maxScore(string s) {
    int ones = 0;
    for (char c : s)
      if (c == '1')
        ones++;

    int score = 0;

    int zeros = 0;
    int ones_found = 0;

    int answer = 0;

    for (int i = 0; i < s.size() - 1; i++) {
      if (s[i] == '0') {
        zeros++;
      } else {
        ones_found++;
      }

      answer = max(answer, zeros + (ones - ones_found));
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
