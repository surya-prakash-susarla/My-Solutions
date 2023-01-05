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
  int minimumRounds(vector<int>& tasks) {
    map<int, int> values;
    for (int i : tasks)
      values[i]++;

    int answer = 0;
    for (const pair<int, int>& i : values) {
      bool found = false;
      for (int j = i.second / 3; j > -1; j--) {
        int t_req = (i.second - (3 * j)) % 2;
        if (t_req == 0) {
          answer += j;
          answer += (i.second - 3 * j) / 2;
          found = true;
          break;
        }
      }
      if (not found)
        return -1;
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
