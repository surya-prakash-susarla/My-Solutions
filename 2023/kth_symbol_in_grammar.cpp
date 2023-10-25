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
  int getval(int n, int k) {
    if (n == 0)
      return 0;
    if (n == 1) {
      return k == 0 ? 0 : 1;
    }

    int current_size = pow(2, n);
    if (k >= current_size / 2) {
      int answer = getval(n - 1, k - (current_size / 2));
      return answer == 0 ? 1 : 0;
    } else {
      return getval(n - 1, k);
    }
  }

  int kthGrammar(int n, int k) { return getval(n - 1, k - 1); }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
