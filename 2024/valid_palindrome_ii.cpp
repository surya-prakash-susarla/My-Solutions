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
  bool is_valid(int i, int j, const string& s) {
    while (i <= j) {
      if (s[i] != s[j])
        return false;
      i++;
      j--;
    }
    return true;
  }

  bool validPalindrome(string s) {
    int i = 0;
    int j = s.size() - 1;

    while (i <= j) {
      if (s[i] != s[j]) {
        return is_valid(i + 1, j, s) or is_valid(i, j - 1, s);
      }
      i++;
      j--;
    }
    return true;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
