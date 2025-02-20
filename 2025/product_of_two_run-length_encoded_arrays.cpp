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

  vvint mul(const vvint& a, const vvint& b) {
    int ai = 0;
    int asub = 0;

    int bi = 0;
    int bsub = 0;

    vvint answer;

    int last_value = -1;
    int counter = 0;

    while (ai < a.size() and bi < b.size()) {
      if (asub == a[ai][1]) {
        asub = 0;
        ai++;
        continue;
      } else if (bsub == b[bi][1]) {
        bsub = 0;
        bi++;
        continue;
      }

      int arem = (a[ai][1] - asub);
      int brem = (b[bi][1] - bsub);

      int chosen_rem = min(arem, brem);

      int value = (a[ai][0] * b[bi][0]);

      answer.push_back({value, chosen_rem});
      asub += chosen_rem;
      bsub += chosen_rem;
    }

    vvint final_answer;
    vint current = answer[0];
    for (int i = 1; i < answer.size(); i++) {
      if (answer[i][0] == current[0]) {
        current[1] += answer[i][1];
      } else {
        final_answer.emplace_back(current);
        current = answer[i];
      }
    }

    final_answer.emplace_back(current);
    return final_answer;
  }

  vector<vector<int>> findRLEArray(vector<vector<int>>& a,
                                   vector<vector<int>>& b) {
    return mul(a, b);
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
