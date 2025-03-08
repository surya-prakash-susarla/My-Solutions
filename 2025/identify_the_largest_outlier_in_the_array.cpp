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
  int getLargestOutlier(vector<int>& input) {
    int sum = 0;
    unordered_map<int, int> values;
    for (int i : input) {
      sum += i;
      values[i]++;
    }

    int answer = INT_MIN;
    for (int i : input) {
      int req = sum - (2 * i);
      if (i == req) {
        if (values[req] > 1)
          answer = max(answer, req);
      } else if (values[req]) {
        answer = max(answer, req);
      }
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
