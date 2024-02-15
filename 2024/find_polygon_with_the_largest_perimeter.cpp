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
  typedef long long ll;
  long long largestPerimeter(vector<int>& values) {
    sort(values.begin(), values.end());

    if (values.size() < 3)
      return -1;

    ll current = values[0] + values[1];
    ll answer = -1;

    for (int i = 2; i < values.size(); i++) {
      if (current > values[i]) {
        answer = max(answer, current + values[i]);
      }
      current += values[i];
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
