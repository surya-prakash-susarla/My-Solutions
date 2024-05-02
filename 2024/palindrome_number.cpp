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
  bool isPalindrome(int x) {
    string orig = to_string(x);
    string temp = orig;
    reverse(temp.begin(), temp.end());
    return temp == orig;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
