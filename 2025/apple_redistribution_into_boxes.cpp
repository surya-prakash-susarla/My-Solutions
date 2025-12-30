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
  int minimumBoxes(vector<int>& input, vector<int>& values) {
    int t = 0;
    for (int i : input)
      t += i;

    int answer = 0;
    sort(values.begin(), values.end());
    reverse(values.begin(), values.end());

    for (int i = 0; i < values.size(); i++) {
      answer++;
      t -= values[i];

      if (t <= 0)
        break;
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
