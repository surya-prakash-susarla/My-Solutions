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
#define mp make_pair
#define is_valid(x, lim) x >= 0 && x < lim

  pair<int, string> __rec__(int x) {
    if (x >= 1000) {
      int r = x / 1000;
      return mp(x % 1000, string(r, 'M'));
    }

    if (x >= 100) {
      if (is_valid(x - 900, 100))
        return mp(x - 900, "CM");
      if (x >= 500)
        return mp(x - 500, "D");
      if (is_valid(x - 400, 100))
        return mp(x - 400, "CD");
      return mp(x % 100, string(x / 100, 'C'));
    }

    if (x >= 10) {
      if (is_valid(x - 90, 10))
        return mp(x - 90, "XC");
      if (x >= 50)
        return mp(x - 50, "L");
      if (is_valid(x - 40, 10))
        return mp(x - 40, "XL");
      return mp(x % 10, string(x / 10, 'X'));
    }

    if (x == 9)
      return mp(x - 9, "IX");
    if (x >= 5)
      return mp(x - 5, "V");
    if (x == 4)
      return mp(x - 4, "IV");

    return mp(0, string(x, 'I'));
  }

  string intToRoman(int value) {
    string answer;

    while (value > 0) {
      pair<int, string> return_value = __rec__(value);
      value = return_value.first;
      answer += return_value.second;
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
