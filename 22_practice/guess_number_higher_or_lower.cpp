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

/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
 public:
  int guessNumber(int n) {
    typedef long long int llint;

    llint lower = 1;
    llint upper = n;

    do {
      int current = (upper + lower) / 2;
      int result = guess(current);
      if (result == -1) {
        upper = current - 1;
      } else if (result == 1) {
        lower = current + 1;
      } else {
        return current;
      }
    } while (true);
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
