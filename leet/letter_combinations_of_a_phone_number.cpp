#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#include <vector>
#include <unordered_map>

// Problem:

typedef long long int llint;
typedef long double ldouble;

using namespace std;

class Solution {
 public:
  unordered_map<char, vector<char>> values = {{'0', {}},
                                              {'1', {}},
                                              {'2', {'a', 'b', 'c'}},
                                              {'3', {'d', 'e', 'f'}},
                                              {'4', {'g', 'h', 'i'}},
                                              {'5', {'j', 'k', 'l'}},
                                              {'6', {'m', 'n', 'o'}},
                                              {'7', {'p', 'q', 'r', 's'}},
                                              {'8', {'t', 'u', 'v'}},
                                              {'9', {'w', 'x', 'y', 'z'}}};

  void __rec__(const vector<vector<char>>& pools,
               const int index,
               string current,
               vector<string>& answer) {
    if (index == current.size()) {
      answer.emplace_back(current);
      return;
    }

    for (const char c : pools[index]) {
      current[index] = c;
      __rec__(pools, index + 1, current, answer);
    }
  }

  vector<string> letterCombinations(string digits) {
    if (digits.size() == 0)
      return {};
    vector<vector<char>> pools;
    for (const char c : digits) {
      // const vector<char> temp = values[c];
      pools.push_back(values[c]);
    }
    vector<string> answer;
    string temp = string(digits.size(), '@');
    __rec__(pools, 0, temp, answer);
    return answer;
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);

  return 0;
}
