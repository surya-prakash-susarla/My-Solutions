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
  int findLeastNumOfUniqueInts(vector<int>& values, int k) {
    map<int, int> temp;
    for (int i : values)
      temp[i]++;

    typedef pair<int, int> pint;
    priority_queue<pint, vector<pint>, greater<pint> > temp2;
    for (auto i : temp)
      temp2.push({i.second, i.first});

    while (k > 0) {
      if (temp2.top().first <= k) {
        k -= temp2.top().first;
        temp2.pop();
      } else {
        break;
      }
    }

    return temp2.size();
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
