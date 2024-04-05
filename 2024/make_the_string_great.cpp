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
  string __calc__(string input) {
    for (int i = 1; i < input.size(); i++) {
      if ((input[i] > input[i - 1] and (input[i] - input[i - 1] == 32)) or
          (input[i - 1] - input[i] == 32)) {
        input[i] = '@';
        input[i - 1] = '@';
      }
    }

    string answer;
    for (char c : input)
      if (c != '@')
        answer += c;

    return answer;
  }

  string makeGood(string input) {
    while (true) {
      string temp = __calc__(input);
      if (temp.size() == input.size())
        break;
      input = temp;
    }
    return input;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
