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
    stack<int> locations;
    vector<int> remove;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '(') {
        locations.push(i);
      } else if (s[i] == ')') {
        if (not locations.empty()) {
          locations.pop();
        } else {
          remove.push_back(i);
        }
      }
    }
    while (not locations.empty()) {
      remove.push_back(locations.top());
      locations.pop();
    }

    for (int i : remove)
      s[i] = '@';

    string answer;
    for (char c : s)
      if (c != '@')
        answer += c;

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
