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
  string shiftingLetters(string s, vector<vector<int>>& shifts) {
    map<pair<int, int>, int> counter;
    for (auto i : shifts) {
      auto it = counter.find({i[0], i[1]});
      if (it == counter.end()) {
        counter[{i[0], i[1]}] = (i[2] == 0 ? -1 : 1);
      } else {
        it->second += (i[2] == 0 ? -1 : 1);
      }
    }

    vector<int> values(s.size(), 0);
    for (auto i : counter) {
      for (int k = i.first.first; k <= i.first.second; k++) {
        values[k] += i.second;
      }
    }

    map<pair<char, int>, char> memo;

    auto get_char = [&](char c, int d) -> char {
      if (d == 0) {
        return c;
      }

      auto it = memo.find({c, d});
      if (it != memo.end())
        return it->second;
      if (d > 0) {
        char answer = 'a' + (((int)(c - 'a') + d) % 26);
        memo[{c, d}] = answer;
        return answer;
      } else {
        int od = d;
        d = -d;
        char answer;
        if (c - 'a' >= d) {
          answer = 'a' + (c - 'a' - d);
        } else {
          d -= (c - 'a');
          d--;
          d %= 26;
          answer = 'z' - d;
        }
        memo[{c, od}] = answer;
        return answer;
      }
    };

    string answer;

    for (int i = 0; i < s.size(); i++) {
      answer += get_char(s[i], values[i]);
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
