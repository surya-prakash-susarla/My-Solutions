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

string isBalanced(string s) {
  stack<char> store;

  auto pop = [&](const char c) -> bool {
    if (store.empty() or store.top() != c)
      return false;
    store.pop();
    return true;
  };

  for (char c : s) {
    switch (c) {
      case '{':
      case '[':
      case '(':
        store.push(c);
        break;
      case '}':
        if (not pop('{'))
          return "NO";
        else
          break;
      case ']':
        if (not pop('['))
          return "NO";
        else
          break;
      case ')':
        if (not pop('('))
          return "NO";
        else
          break;
    }
  }

  return store.empty() ? "YES" : "NO";
}

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
