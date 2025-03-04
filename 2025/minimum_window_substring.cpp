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
    if (t.size() > s.size())
      return "";

    map<char, int> counter;
    for (char c : t) {
      counter[c]++;
    }
    int req = t.size();
    int right = -1;
    for (int i = 0; i < s.size(); i++) {
      if (counter.contains(s[i])) {
        counter[s[i]]--;
        if (counter[s[i]] > -1)
          req--;
      }
      if (req == 0) {
        right = (i + 1);
        break;
      }
    }
    if (right == -1)
      return "";

    int left = 0;
    auto moveLeft = [&]() {
      for (int i = left; i < right; i++) {
        if (counter.contains(s[i])) {
          if (counter[s[i]] + 1 > 0) {
            left = i;
            return;
          } else {
            counter[s[i]]++;
          }
        }
      }
      left = right - 1;
    };

    // yank left from useless position.
    moveLeft();

    int answer = (right - left);
    string answer_value = s.substr(left, right - left);

    for (int i = right; i < s.size(); i++) {
      right = i;
      if (counter.contains(s[i])) {
        counter[s[i]]--;
        moveLeft();
        int size = (right - left + 1);
        if (size < answer) {
          answer = size;
          answer_value = s.substr(left, size);
        }
      }
    }

    return answer_value;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
