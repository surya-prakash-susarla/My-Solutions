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
  string removeStars(string s) {
    int count = 0;
    for (int i = s.size() - 1; i > -1; i--) {
      if (s[i] == '*') {
        s[i] = '@';
        count++;
      } else if (count > 0) {
        s[i] = '@';
        count--;
      }
    }
    string answer;
    for (char c : s)
      if (c != '@')
        answer += c;

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
