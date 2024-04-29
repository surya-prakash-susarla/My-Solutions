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
  vector<int> productExceptSelf(vector<int>& values) {
    const int n = values.size();
    vector<int> prefix(n);
    vector<int> suffix(n);

    suffix[n - 1] = values[n - 1];
    for (int i = n - 2; i > -1; i--)
      suffix[i] = values[i] * suffix[i + 1];
    prefix[0] = values[0];
    for (int i = 1; i < n; i++)
      prefix[i] = values[i] * prefix[i - 1];

    vector<int> answer(n);
    answer[0] = suffix[1];
    answer[n - 1] = prefix[n - 2];

    for (int i = 1; i < n - 1; i++)
      answer[i] = prefix[i - 1] * suffix[i + 1];

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
