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
  unordered_set<string> answer;
  int maxval = 0;
  string input;

  void __rec__(int index, int oc, string& current) {
    if (index == input.size()) {
      if (not oc) {
        if (current.size() == maxval) {
          answer.insert(current);
        } else if (current.size() > maxval) {
          maxval = current.size();
          answer.clear();
          answer.insert(current);
        }
      }
      return;
    }
    if (input[index] == '(') {
      __rec__(index + 1, oc, current);
      current.push_back(input[index]);
      __rec__(index + 1, oc + 1, current);
      current.pop_back();
    } else if (input[index] == ')') {
      if (oc) {
        current.push_back(input[index]);
        __rec__(index + 1, oc - 1, current);
        current.pop_back();
      }
      __rec__(index + 1, oc, current);
    } else {
      current.push_back(input[index]);
      __rec__(index + 1, oc, current);
      current.pop_back();
    }
  }

  vector<string> removeInvalidParentheses(string s) {
    input = s;
    string temp;
    __rec__(0, 0, temp);
    return vector<string>(answer.begin(), answer.end());
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
