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
  int longestValidParentheses(string s) {
    vector<int> match(s.size(), -1);

    stack<int> locations;

    for (int i = 0; i < s.size(); i++) {
      if (s[i] == ')') {
        if (locations.empty())
          continue;
        int latest = locations.top();
        locations.pop();
        match[latest] = i;
        match[i] = latest;
      } else {
        locations.push(i);
      }
    }

    int answer = 0;
    int current = 0;
    for (int i = 0; i < s.size(); i++) {
      if (match[i] != -1) {
        current++;
      } else {
        answer = max(answer, current);
        current = 0;
      }
    }
    answer = max(answer, current);
    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
