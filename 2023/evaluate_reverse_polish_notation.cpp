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
  int evalRPN(vector<string>& input) {
    stack<int> values;

    auto handle = [&](const string& ref) -> bool {
      if (ref == "+") {
        int second = values.top();
        values.pop();
        int first = values.top();
        values.pop();
        values.push(first + second);
        return true;
      } else if (ref == "-") {
        int second = values.top();
        values.pop();
        int first = values.top();
        values.pop();
        values.push(first - second);
        return true;
      } else if (ref == "*") {
        int second = values.top();
        values.pop();
        int first = values.top();
        values.pop();
        values.push(first * second);
        return true;
      } else if (ref == "/") {
        int second = values.top();
        values.pop();
        int first = values.top();
        values.pop();
        values.push(first / second);
        return true;
      }
      return false;
    };

    for (const string& ref : input) {
      if (handle(ref)) {
        continue;
      } else {
        values.push(stoi(ref));
      }
    }

    return values.top();
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
