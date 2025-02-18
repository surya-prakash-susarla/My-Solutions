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
  int lengthOfLongestSubstring(string s) {
    unordered_map<char, bool> used;

    int maxlen = 0;

    int left = 0;
    int right = 0;

    while (right < s.size()) {
      while (used[s[right]])
        used[s[left++]] = false;

      used[s[right++]] = true;
      maxlen = max(maxlen, (right - left));
    }

    return maxlen;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
