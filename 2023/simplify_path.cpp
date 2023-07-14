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
  string simplifyPath(string input) {
    stack<string> values;
    string current;

    const string previous_folder = "..";
    const string current_folder = ".";

    auto handle = [&](const string& ref) {
      if (ref == previous_folder) {
        if (not values.empty())
          values.pop();
        return;
      }
      if (ref == current_folder) {
        return;
      }
      values.push(ref);
    };

    for (char c : input) {
      if (c == '/') {
        if (not current.empty()) {
          handle(current);
          current.clear();
        }
      } else {
        current = current + c;
      }
    }

    if (not current.empty())
      handle(current);

    if (values.empty()) {
      return "/";
    }

    string answer = values.top();
    values.pop();

    while (not values.empty()) {
      answer = values.top() + "/" + answer;
      values.pop();
    }

    answer = "/" + answer;

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
