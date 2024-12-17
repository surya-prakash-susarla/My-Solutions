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
  string repeatLimitedString(string s, int repeatLimit) {
    map<char, int> counts;
    for (char c : s)
      counts[c]++;

    string answer;

    for (auto it = counts.rbegin(); it != counts.rend(); it = next(it)) {
      int current_value = it->second;
      bool first_iteration = true;
      while (current_value > 0) {
        if (not first_iteration) {
          auto temp = next(it);
          if (temp == counts.rend()) {
            return answer;
          } else {
            answer += temp->first;
            temp->second--;
            if (temp->second == 0)
              counts.erase(temp->first);
          }
        } else {
          first_iteration = false;
        }
        int picked = min(current_value, repeatLimit);
        answer += string(picked, it->first);
        current_value -= picked;
      }
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
