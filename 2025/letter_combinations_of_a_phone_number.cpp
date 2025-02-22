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

  void __rec__(int ind,
               const string& digits,
               string current,
               unordered_map<int, vector<char>>& values) {
    if (ind == digits.size()) {
      answer.emplace_back(current);
      return;
    }

    for (char c : values[digits[ind] - '0'])
      __rec__(ind + 1, digits, current + c, values);
  }

  vector<string> letterCombinations(string digits) {
    if (digits.empty())
      return {};

    unordered_map<int, vector<char>> values;
    values[2] = {'a', 'b', 'c'};
    values[3] = {'d', 'e', 'f'};
    values[4] = {'g', 'h', 'i'};
    values[5] = {'j', 'k', 'l'};
    values[6] = {'m', 'n', 'o'};
    values[7] = {'p', 'q', 'r', 's'};
    values[8] = {'t', 'u', 'v'};
    values[9] = {'w', 'x', 'y', 'z'};

    __rec__(0, digits, "", values);

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
