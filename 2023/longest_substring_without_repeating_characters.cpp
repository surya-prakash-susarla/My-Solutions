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
    if (input.size() == 0)
      return 0;

    unordered_map<char, int> ind;

    int answer = 1;
    int left = 0;
    int right = 1;
    ind[input[left]] = left;

    while (left <= right and right < input.size()) {
      auto it = ind.find(input[right]);
      if (it == ind.end() or it->second < left) {
        answer = max(answer, right - left + 1);
        ind[input[right]] = right;
      } else {
        left = it->second + 1;
        it->second = right;
        answer = max(answer, right - left + 1);
      }
      right++;
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
