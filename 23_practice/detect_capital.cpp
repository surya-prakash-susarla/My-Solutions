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
  bool detectCapitalUse(string word) {
    if (word.size() == 1)
      return true;

    bool is_lower_case_rem_string = islower(word[1]);
    for (char c : word.substr(2)) {
      bool current = islower(c);
      if (current != is_lower_case_rem_string)
        return false;
    }
    if (not is_lower_case_rem_string and isupper(word[0]))
      return true;
    if (is_lower_case_rem_string)
      return true;
    return false;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
