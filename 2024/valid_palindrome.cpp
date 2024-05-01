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
  bool isPalindrome(string input) {
    string convert;
    for (char c : input) {
      if (isalnum(c)) {
        if (isalpha(c))
          convert += tolower(c);
        else
          convert += c;
      }
    }
    int left = 0;
    int right = convert.size() - 1;

    while (left <= right) {
      if (convert[left] != convert[right])
        return false;

      left++;
      right--;
    }

    return true;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
