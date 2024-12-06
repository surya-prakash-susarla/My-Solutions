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
  int maxCount(vector<int>& banned, int n, int maxSum) {
    int answer = 0;
    int csum = 0;

    set<int> temp(banned.begin(), banned.end());

    for (int i = 1; i <= n; i++) {
      if (temp.find(i) != temp.end())
        continue;

      if (csum + i > maxSum)
        break;

      csum += i;
      answer++;
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
