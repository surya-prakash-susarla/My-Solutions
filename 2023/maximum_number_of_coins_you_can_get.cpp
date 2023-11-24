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
  int maxCoins(vector<int>& values) {
    sort(values.begin(), values.end(), greater<int>());
    int answer = 0;
    const int t = values.size() / 3;
    for (int i = 1, k = 0; k < t; i += 2, k++)
      answer += values[i];
    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
