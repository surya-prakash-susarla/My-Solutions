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
  string minRemoveToMakeValid(string s) {
    stack<pair<char, int>> values;
    string answer;
    for (int i = 0; i < s.size(); i++) {
      switch (s[i]) {
        case '(': {
          answer += s[i];
          values.push({s[i], answer.size() - 1});
          break;
        }
        case ')': {
          if (not values.empty()) {
            values.pop();
            answer += s[i];
          }
          break;
        }
        default: {
          answer += s[i];
        }
      }
    }

    while (not values.empty()) {
      answer[values.top().second] = '@';
      values.pop();
    }

    string return_value;
    for (char c : answer)
      if (c != '@')
        return_value += c;

    return return_value;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
