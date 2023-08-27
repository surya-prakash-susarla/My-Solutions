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
  int value(int n) {
    int answer = 0;
    while (n) {
      int temp = n % 10;
      answer += (temp * temp);
      n /= 10;
    }
    return answer;
  }

  bool isHappy(int n) {
    set<int> covered;
    while (covered.find(n) == covered.end()) {
      covered.insert(n);
      n = value(n);
      if (n == 1)
        return true;
    }
    return false;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
