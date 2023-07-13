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
  typedef struct _node {
    char c;
    map<char, struct _node> children;
    bool is_ending;
    vector<int> result;

    void add_word(const string& value, int index, const int& n) {
      if (index == value.size()) {
        is_ending = true;
      } else {
        if (children[value[index]].result.empty()) {
          children[value[index]].result = vector<int>(n, -1);
        }
        children[value[index]].c = value[index];
        children[value[index]].add_word(value, index + 1, n);
      }
    }
  } node;

  node root;

  bool __rec__(const string& input, int index, node& current) {
    if (index == input.size())
      return current.is_ending;

    if (current.result[index] != -1)
      return current.result[index] == 1;

    auto it = current.children.find(input[index]);
    if (it == current.children.end())
      return false;

    if (it->second.is_ending) {
      bool result = __rec__(input, index + 1, root);
      if (result) {
        current.result[index] = true;
        return true;
      }
    }
    current.result[index] = __rec__(input, index + 1, it->second);
    return current.result[index];
  }

  bool wordBreak(string input, vector<string>& words) {
    int n = input.size();

    root.is_ending = false;
    root.c = '@';
    root.result = vector<int>(n, -1);

    for (const string& i : words) {
      root.add_word(i, 0, n);
    }

    return __rec__(input, 0, root);
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
