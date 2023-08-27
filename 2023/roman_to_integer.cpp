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
  inline int get_value(char c) {
    switch (c) {
      case 'I':
        return 1;
      case 'V':
        return 5;
      case 'X':
        return 10;
      case 'L':
        return 50;
      case 'C':
        return 100;
      case 'D':
        return 500;
      default:
      case 'M':
        return 1000;
    }
  }

  pair<bool, int> get_combo(int i, const string& value) {
    if (i + 1 >= value.size())
      return make_pair(false, -1);

    char a = value[i];
    char b = value[i + 1];

#define ret(x, y, c)     \
  if (a == x and b == y) \
    return make_pair(true, c);

    ret('I', 'V', 4);
    ret('I', 'X', 9);
    ret('X', 'L', 40);
    ret('X', 'C', 90);
    ret('C', 'D', 400);
    ret('C', 'M', 900);

    return make_pair(false, -1);
  }

  int romanToInt(string input) {
    int answer = 0;

    for (int i = 0; i < input.size();) {
      const pair<bool, int> cval = get_combo(i, input);
      if (cval.first) {
        answer += cval.second;
        i += 2;
      } else {
        answer += get_value(input[i]);
        i++;
      }
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
