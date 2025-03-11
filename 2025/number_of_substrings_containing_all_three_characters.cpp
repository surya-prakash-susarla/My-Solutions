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
  int numberOfSubstrings(string input) {
    int answer = 0;
    int a_count = 0;
    int b_count = 0;
    int c_count = 0;

    auto is_valid = [&]() -> bool { return a_count and b_count and c_count; };

    int left = 0;
    int right = 1;

    auto update = [](int& ref, const bool red) {
      if (red)
        ref--;
      else
        ref++;
    };

    auto update_count = [&](char c, bool red = false) {
      switch (c) {
        case 'a':
          update(a_count, red);
          return;
        case 'b':
          update(b_count, red);
          return;
        case 'c':
          update(c_count, red);
          return;
      }
    };

    update_count(input[left]);

    bool is_first = true;

    while (right < input.size()) {
      update_count(input[right]);
      if (is_valid()) {
        int current = 0;
        while (is_valid() and left <= right) {
          if (is_first) {
            if (left > 0)
              current += (left);
            is_first = false;
          }

          current += (input.size() - right);
          update_count(input[left], true);
          left++;
        }
        answer += current;
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
