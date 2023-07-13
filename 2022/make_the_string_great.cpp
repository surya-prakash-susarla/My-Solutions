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
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

typedef long long int llint;
typedef long long unsigned int ullint;

using namespace std;

class Solution {
 public:
  bool is_valid(char a, char b) {
    if ((islower(a) and isupper(b)) or (isupper(a) and islower(b)))
      return tolower(a) == tolower(b);
    return false;
  }

  string makeGood(string value) {
    int left = 0;
    int right = 1;

    while (right < value.size()) {
      if (is_valid(value[left], value[right])) {
        value[left] = '@';
        value[right] = '@';
        right++;

        while (left > -1)
          if (value[left] == '@')
            left--;
          else
            break;

        if (left == -1) {
          left = right++;
        }
      } else {
        left = right;
        right++;
      }
    }

    string answer;
    for (char c : value)
      if (c != '@')
        answer += c;

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
