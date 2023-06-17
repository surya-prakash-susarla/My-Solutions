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
  map<int, int> values;

  bool allowed(int value) {
    auto it = values.lower_bound(value);

    int sum = 0;
    for (; it != values.end(); it++) {
      sum += it->second;
    }

    return sum >= value;
  }

  int hIndex(vector<int>& input) {
    for (int i : input)
      values[i]++;

    int minvalue = 0;
    int maxvalue = min((int)input.size(), values.rbegin()->first);

    int answer = 0;

    while (minvalue <= maxvalue) {
      int midvalue = (maxvalue + minvalue) / 2;

      // cout << "maxvalue : " << maxvalue << endl;
      // cout << "minvalue : " << minvalue << endl;
      // cout << "current value : " << midvalue << endl;

      if (allowed(midvalue)) {
        answer = midvalue;
        minvalue = midvalue + 1;
      } else {
        maxvalue = midvalue - 1;
      }
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
