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
  int totalMoney(int n) {
    int answer = 0;

    for (int init = 1; n > 0 and n--;) {
      answer += init;
      for (int i = 1, current = init; i < 7 & n > 0; i++, n--) {
        current++;
        answer += current;
      }
      init++;
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
