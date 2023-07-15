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
  vector<string> answer;

  void __rec__(int index,
               string value,
               const string& input,
               unordered_map<char, vector<char>>& cons) {
    if (index == input.size()) {
      if (not value.empty())
        answer.emplace_back(value);
      return;
    }

    for (char c : cons[input[index]]) {
      __rec__(index + 1, value + c, input, cons);
    }
  }

  vector<string> letterCombinations(string digits) {
    unordered_map<char, vector<char>> cons;
    cons['2'] = {'a', 'b', 'c'};
    cons['3'] = {'d', 'e', 'f'};
    cons['4'] = {'g', 'h', 'i'};
    cons['5'] = {'j', 'k', 'l'};
    cons['6'] = {'m', 'n', 'o'};
    cons['7'] = {'p', 'q', 'r', 's'};
    cons['8'] = {'t', 'u', 'v'};
    cons['9'] = {'w', 'x', 'y', 'z'};

    __rec__(0, "", digits, cons);

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
