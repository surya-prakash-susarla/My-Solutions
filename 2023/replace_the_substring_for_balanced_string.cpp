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
  inline bool valid(map<char, int>& current, map<char, int>& target) {
    for (auto i : target)
      if (current[i.first] < i.second)
        return false;
    return true;
  }

  int balancedString(string input) {
    map<char, int> f;
    for (char c : input)
      f[c]++;

    int rs = input.size() / 4;
    map<char, int> r;
    for (auto i : f)
      if (i.second > rs)
        r[i.first] = i.second - rs;

    if (r.empty())
      return 0;

    int answer = input.size();
    {
      int lp = 0;
      int rp = 1;
      map<char, int> c;
      c[input[lp]]++;

      while (rp < input.size() + 1) {
        if (valid(c, r)) {
          answer = min(answer, (rp - lp));
          c[input[lp++]]--;
        } else {
          c[input[rp++]]++;
        }
      }
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
