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
  string minWindow(string s, string t) {
    map<char, int> reqs;
    map<char, bool> is_req;
    for (char c : t) {
      reqs[c]++;
      is_req[c] = true;
    }

    int total_req = t.size();

    int left = 0;
    int right = 1;

    if (is_req[s[left]]) {
      reqs[s[left]]--;
      total_req--;
    }

    int start = -1;
    int end = -1;

    while (left < right and right < s.size()) {
      if (total_req == 0) {
        if ((start == -1 and end == -1) or (right - left < end - start + 1)) {
          end = right - 1;
          start = left;
        }

        if (is_req[s[left]]) {
          if (reqs[s[left]] >= 0)
            total_req++;
          reqs[s[left]]++;
        }
        left++;
      } else {
        if (is_req[s[right]]) {
          if (reqs[s[right]] > 0)
            total_req--;
          reqs[s[right]]--;
        }
        right++;
      }
    }

    for (int i = left; total_req == 0 and i < right; i++) {
      if ((start == -1 and end == -1) or (right - i < end - start + 1)) {
        start = i;
        end = right;
      }
      if (is_req[s[i]]) {
        if (reqs[s[i]] == 0) {
          total_req++;
        }
        reqs[s[i]]++;
      }
    }

    if (start != -1 and end != -1)
      return s.substr(start, end - start + 1);
    return string();
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
