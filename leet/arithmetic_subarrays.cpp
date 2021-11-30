#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#include <vector>

// Problem:

typedef long long int llint;
typedef long double ldouble;

using namespace std;

class Solution {
 public:
  vector<bool> checkArithmeticSubarrays(vector<int>& values,
                                        vector<int>& l,
                                        vector<int>& r) {
    auto is_valid = [&](int l, int r) -> bool {
      if (l == r or l - r == 1)
        return true;

      vector<int> temp;
      copy(values.begin() + l, values.begin() + r + 1, back_inserter(temp));

      sort(temp.begin(), temp.end());

      int diff = temp[1] - temp[0];

      for (int i = 2; i < temp.size(); i++)
        if (temp[i] - temp[i - 1] != diff)
          return false;
      return true;
    };

    vector<bool> answer(l.size(), false);
    for (int i = 0; i < l.size(); i++) {
      answer[i] = is_valid(l[i], r[i]);
    }

    return answer;
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);

  return 0;
}
