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
  vector<vector<int>> intervalIntersection(vector<vector<int>>& a,
                                           vector<vector<int>>& b) {
    typedef vector<int> vint;
    typedef vector<vint> vvint;

    auto interval = [](const vint& a, const vint& b) -> vint {
      return {max(a[0], b[0]), min(a[1], b[1])};
    };

    auto can_intersect = [&](const vint& a, const vint& b) -> bool {
      vint temp = interval(a, b);
      return temp[0] <= temp[1];
    };

    int left = 0;
    int right = 0;

    vvint answer;

    auto print = [](const vint& a) { cout << a[0] << " " << a[1]; };

    while (left < a.size() and right < b.size()) {
      // cout << "loc -> left : ";
      // print(a[left]);
      // cout << " , right : ";
      // print(b[right]);
      // cout << endl;

      if (can_intersect(a[left], b[right])) {
        // cout << "intersection possible" << endl;
        const vint result = interval(a[left], b[right]);

        // cout << "result : ";
        // print(result);
        // cout << endl;

        answer.emplace_back(result);
      }

      if (a[left][1] > b[right][1]) {
        // cout << "moving right ptr" << endl;
        right++;
      } else {
        // cout << "moving left ptr" << endl;
        left++;
      }
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
