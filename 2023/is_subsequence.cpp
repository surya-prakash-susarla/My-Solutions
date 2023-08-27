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
  bool isSubsequence(string input, string value) {
    if (input.size() == 0)
      return true;
    if (value.size() == 0)
      return false;
    int i = 0;
    int j = 0;
    while (true) {
      if (input[i] == value[j]) {
        i++;
      }
      j++;

      if (i == input.size())
        return true;
      if (j == value.size())
        return false;
    }
    return false;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
