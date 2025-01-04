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
  int count(const pair<int, int>& ind, const string& s) {
    if (ind.first == ind.second)
      return 0;

    vector<bool> used(26, false);
    int answer = 0;
    for (int i = ind.first + 1; i < ind.second; i++) {
      if (not used[s[i] - 'a']) {
        used[s[i] - 'a'] = true;
        answer++;
      }
    }
    return answer;
  }

  int countPalindromicSubsequence(string s) {
    map<char, pair<int, int>> values;

    for (int i = 0; i < s.size(); i++) {
      auto it = values.find(s[i]);
      if (it == values.end()) {
        values[s[i]] = {i, i};
      } else {
        it->second.second = i;
      }
    }

    int answer = 0;
    for (auto i : values) {
      answer += count(i.second, s);
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
