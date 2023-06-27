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
  vector<vector<int>> kSmallestPairs(vector<int>& a, vector<int>& b, int k) {
    typedef pair<int, int> pint;
    typedef pair<int, pint> ppint;

    multiset<ppint> values;

    auto get = [](int b, int c) -> ppint {
      return make_pair(b + c, make_pair(b, c));
    };

    for (int i = 0; i < k and i < a.size(); i++) {
      for (int j = 0; j < k and j < b.size(); j++) {
        if (values.size() == k) {
          if (values.rbegin()->first > a[i] + b[j]) {
            values.erase(next(values.end(), -1));
            values.insert(get(a[i], b[j]));
          } else {
            break;
          }
        } else {
          values.insert(get(a[i], b[j]));
        }
      }
    }

    typedef vector<int> vint;
    typedef vector<vint> vvint;

    vvint answer;
    for (ppint i : values) {
      answer.push_back({i.second.first, i.second.second});
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
