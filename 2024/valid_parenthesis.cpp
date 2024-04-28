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
  bool isValid(string s) {
    stack<char> temp;
    for (char c : s) {
      switch (c) {
        case '(':
          temp.push(c);
          break;
        case '[':
          temp.push(c);
          break;
        case '{':
          temp.push(c);
          break;
        case ')':
          if (temp.empty() or temp.top() != '(')
            return false;
          else
            temp.pop();
          break;
        case ']':
          if (temp.empty() or temp.top() != '[')
            return false;
          else
            temp.pop();
          break;
        case '}':
          if (temp.empty() or temp.top() != '{')
            return false;
          else
            temp.pop();
          break;
      }
    }
    return temp.empty();
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
