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
  int trailingZeroes(int n) {
    int answer = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = i; j % 5 == 0; j /= 5)
        answer++;
    }
    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
