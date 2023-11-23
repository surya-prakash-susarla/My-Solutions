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
  bool is_valid(vector<int> values, int i, int j) {
    if (i == j)
      return true;

    sort(next(values.begin(), i), next(values.begin(), j + 1));

    const int diff = values[i + 1] - values[i];
    for (int k = i + 1; k <= j; k++)
      if (values[k] - values[k - 1] != diff)
        return false;
    return true;
  }

  vector<bool> checkArithmeticSubarrays(vector<int>& values,
                                        vector<int>& l,
                                        vector<int>& r) {
    int qsize = l.size();

    vector<bool> answer;

    for (int i = 0; i < qsize; i++)
      answer.push_back(is_valid(values, l[i], r[i]));

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
