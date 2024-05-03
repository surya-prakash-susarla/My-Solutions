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
  int countPrimes(int n) {
    if (n < 2)
      return 0;
    vector<int> temp(n + 1);
    for (int i = 2; i < n; i++)
      temp[i] = i;

    int answer = 0;
    for (int i = 2; i < n; i++) {
      if (temp[i] == -1)
        continue;
      answer++;
      for (int j = 2; (temp[i] * j) < (n + 1); j++)
        temp[temp[i] * j] = -1;
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
