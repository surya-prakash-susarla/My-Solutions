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
  static constexpr int modvalue = 1000000007;
  typedef unsigned long long int llint;

  int numberOfWays(string values) {
    const int n = values.size();
    bool temp = false;
    int start = -1;
    for (int i = n - 1; i > -1; i--) {
      if (values[i] == 'S') {
        if (temp) {
          start = i;
          break;
        } else {
          temp = true;
        }
      }
    }

    if (start < 0)
      return 0;

    llint combinations = 1;
    bool end_seat_found = false;
    int plants = 0;
    for (int i = start - 1; i > -1; i--) {
      if (values[i] == 'P') {
        if (end_seat_found) {
          continue;
        } else {
          plants++;
        }
      } else {
        if (end_seat_found) {
          end_seat_found = false;
          combinations = (plants + 1) * combinations;
          plants = 0;
          combinations %= modvalue;
        } else {
          end_seat_found = true;
        }
      }
    }

    if (end_seat_found == true)
      return 0;
    else
      return combinations;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
