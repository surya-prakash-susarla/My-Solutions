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
  int findMaxLength(vector<int>& input) {
    int csum = 0;
    unordered_map<int, int> locs;
    locs[0] = -1;

    int answer = 0;
    for (int i = 0; i < input.size(); i++) {
      csum += (input[i] == 0 ? -1 : 1);
      auto it = locs.find(csum);
      if (it != locs.end()) {
        answer = max(answer, i - it->second);
      } else {
        locs[csum] = i;
      }
    }
    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
