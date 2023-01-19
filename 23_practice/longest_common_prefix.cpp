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
  string longestCommonPrefix(vector<string>& values) {
    string answer;
    int index = 0;
    bool is_allowed = true;
    while (is_allowed) {
      optional<char> first_char = nullopt;
      for (int i = 0; i < values.size(); i++) {
        if (index >= values[i].size()) {
          is_allowed = false;
          break;
        } else {
          if (first_char and values[i][index] != *first_char) {
            is_allowed = false;
            break;
          } else if (not first_char.has_value()) {
            first_char = values[i][index];
          }
        }
      }
      if (is_allowed)
        answer = answer + *first_char;
      index++;
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
