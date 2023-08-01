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
  int maxProfit(vector<int>& values) {
    int maxvalue = *values.rbegin();
    int answer = 0;
    for (int i = values.size() - 2; i > -1; i--) {
      answer = max(answer, maxvalue - values[i]);
      if (values[i] > maxvalue)
        maxvalue = values[i];
    }
    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
