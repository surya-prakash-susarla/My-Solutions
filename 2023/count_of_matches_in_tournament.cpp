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
  int get(int value) {
    if (value % 2 == 0)
      return value / 2;
    else
      return (value - 1) / 2 + 1;
  }

  int numberOfMatches(int n) {
    int answer = 0;
    while (n != 1) {
      int temp = get(n);
      if (n % 2 == 0)
        answer += temp;
      else
        answer += temp - 1;
      n = temp;
    }
    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
