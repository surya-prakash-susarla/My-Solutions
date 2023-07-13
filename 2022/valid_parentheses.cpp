#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool isValid(string s) {
    auto opp = [](char c) -> char {
      switch (c) {
        case '}':
          return '{';
        case ')':
          return '(';
        default:
          return '[';
      }
    };

    stack<char> temp;

    for (char c : s) {
      if (c == '(' or c == '[' or c == '{')
        temp.push(c);
      else if (temp.empty() or temp.top() != opp(c))
        return false;
      else
        temp.pop();
    }

    return temp.empty();
  }
};

int main() {
  return 0;
}
