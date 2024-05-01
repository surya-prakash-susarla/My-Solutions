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
  vector<char> get_chars(char num) {
    switch (num) {
      case '2':
        return {'a', 'b', 'c'};
      case '3':
        return {'d', 'e', 'f'};
      case '4':
        return {'g', 'h', 'i'};
      case '5':
        return {'j', 'k', 'l'};
      case '6':
        return {'m', 'n', 'o'};
      case '7':
        return {'p', 'q', 'r', 's'};
      case '8':
        return {'t', 'u', 'v'};
      case '9':
        return {'w', 'x', 'y', 'z'};
    }
    return {};
  }

  vector<string> answer;

  void __rec__(int index, vector<char> current, const string& input) {
    if (index == input.size()) {
      answer.emplace_back(string(current.begin(), current.end()));
      return;
    }
    vector<char> chars = get_chars(input[index]);
    for (char c : chars) {
      vector<char> temp = current;
      temp.push_back(c);
      __rec__(index + 1, temp, input);
    }
  }

  vector<string> letterCombinations(string digits) {
    if (digits.empty())
      return {};
    __rec__(0, {}, digits);
    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
