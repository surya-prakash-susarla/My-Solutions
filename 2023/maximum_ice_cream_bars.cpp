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
  int maxIceCream(vector<int>& values, int limit) {
    sort(values.begin(), values.end());

    int answer = 0;
    for (int i = 0; i < values.size(); i++) {
      if (values[i] <= limit) {
        answer++;
        limit -= values[i];
      }

      if (limit == 0)
        break;
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
