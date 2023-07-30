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
  bool isPalindrome(string x) {
    string input;
    for (char c : x)
      if (isalnum(c))
        input += tolower(c);
    string temp(input);
    reverse(temp.begin(), temp.end());
    return temp == input;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
