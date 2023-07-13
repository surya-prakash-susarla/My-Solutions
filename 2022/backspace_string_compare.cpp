#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  bool backspaceCompare(string s, string t) {
    stack<char> a;

    for (char c : s) {
      if (c == '#') {
        if (not a.empty())
          a.pop();
      } else {
        a.push(c);
      }
    }

    stack<char> b;
    for (char c : t) {
      if (c == '#') {
        if (not b.empty())
          b.pop();
      } else {
        b.push(c);
      }
    }

    if (a.size() != b.size())
      return false;

    while (!a.empty()) {
      if (a.top() != b.top())
        return false;
      a.pop();
      b.pop();
    }

    return true;
  }
};
