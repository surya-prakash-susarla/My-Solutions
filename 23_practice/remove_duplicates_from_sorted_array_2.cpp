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
  int removeDuplicates(vector<int>& values) {
    int dup = 1;
    int tdup = 0;

    for (int i = 1; i < values.size(); i++) {
      if (values[i] != values[i - 1]) {
        if (values[i] < values[i - 1])
          break;
        if (dup > 2) {
          dup -= 2;
          int prev_value = values[i - 1];
          for (int j = i - dup; j < values.size() - dup; j++)
            values[j] = values[j + dup];
          for (int j = values.size() - dup; j < values.size(); j++)
            values[j] = prev_value;
          tdup += dup;
          i = i - dup;
        }
        dup = 1;
      } else {
        dup++;
      }
    }

    if (dup > 2)
      tdup += (dup - 2);

    return values.size() - tdup;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
