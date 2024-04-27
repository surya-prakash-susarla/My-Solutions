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
  int lengthOfLongestSubstring(string input) {
    if (input.empty())
      return 0;

    int left = 0;
    int right = 1;

    int answer = 1;
    map<char, bool> used;
    used[input[left]] = true;

    while (left <= right and right < input.size()) {
      if (not used[input[right]]) {
        answer = max(answer, right - left + 1);
        used[input[right]] = true;
        right++;
      } else {
        used[input[left]] = false;
        left++;
      }
    }

    if (left < right)
      answer = max(answer, right - left);

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
