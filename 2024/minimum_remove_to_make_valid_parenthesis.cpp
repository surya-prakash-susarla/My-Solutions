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
  string minRemoveToMakeValid(string input) {
    stack<int> temp;

    string answer;

    for (int i = 0; i < input.size(); i++) {
      const char c = input[i];
      if (c == ')') {
        if (temp.empty()) {
          continue;
        } else {
          temp.pop();
          answer += c;
        }
      } else if (c == '(') {
        temp.push(i);
        answer += c;
      } else {
        answer += c;
      }
    }

    int trim = temp.size();
    for (int i = answer.size() - 1; trim > 0 and i > -1; i--) {
      if (answer[i] == '(') {
        trim--;
        answer[i] = '@';
      }
    }

    string fanswer;
    for (char c : answer)
      if (c != '@')
        fanswer += c;

    return fanswer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
