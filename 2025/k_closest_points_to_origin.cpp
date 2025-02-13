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
  typedef vector<int> vint;
  typedef vector<vint> vvint;

  int dist(const vint& input) {
    return (input[0] * input[0]) + (input[1] * input[1]);
  }

  vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    map<int, vvint> values;
    for (vint i : points)
      values[dist(i)].emplace_back(i);

    vvint answer;

    for (auto i : values) {
      if (i.second.size() > k) {
        for (int j = 0; j < k; j++)
          answer.emplace_back(i.second[j]);
      } else {
        k -= i.second.size();
        answer.insert(answer.end(), i.second.begin(), i.second.end());
      }
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
