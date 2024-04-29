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
  int maxSubArray(vector<int>& values) {
    int maxvalue = values[values.size() - 1];
    int answer = maxvalue;

    for (int i = values.size() - 2; i > -1; i--) {
      maxvalue = max(values[i], maxvalue + values[i]);
      answer = max(answer, maxvalue);
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
