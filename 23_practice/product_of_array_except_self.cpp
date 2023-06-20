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
    int n = values.size();
    typedef vector<int> vint;

    vint pre(n, 1);
    vint suf(n, 1);

    {
      int temp = 1;
      for (int i = 1; i < n; i++) {
        pre[i] = pre[i - 1] * values[i - 1];
      }
    }
    {
      int temp = 1;
      for (int i = n - 2; i > -1; i--) {
        suf[i] = suf[i + 1] * values[i + 1];
      }
    }

    vint answer(n);
    for (int i = 0; i < n; i++)
      answer[i] = pre[i] * suf[i];

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
