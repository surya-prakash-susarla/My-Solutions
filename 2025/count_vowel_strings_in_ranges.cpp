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
  inline int is_valid(const string& s) {
    auto is_vowel = [](const char c) -> bool {
      switch (c) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
          return true;
        default:
          return false;
      }
    };

    return is_vowel(s[0]) and is_vowel(*s.rbegin()) ? 1 : 0;
  }

  vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& input) {
    vector<int> counts(words.size(), 0);

    int prev = 0;
    for (int i = words.size() - 1; i > -1; i--) {
      counts[i] = prev + (is_valid(words[i]));
      prev = counts[i];
    }

    vector<int> answer;
    for (int i = 0; i < input.size(); i++) {
      const int first = counts[input[i][0]];
      const int second =
          (input[i][1] + 1 >= counts.size() ? 0 : counts[input[i][1] + 1]);
      answer.push_back(first - second);
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
