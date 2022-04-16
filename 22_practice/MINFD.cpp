#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <map>
#include <memory>
#include <numeric>
#include <set>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <utility>
#include <vector>

#define in scanf
#define out printf

using namespace std;

// Problem:

typedef long long int llint;
typedef long double ldouble;

llint __calc__() {
  llint n, x;
  cin >> n >> x;
  vector<llint> values(n);
  llint tsum = 0;
  for (llint i = 0; i < n; i++) {
    cin >> values[i];
    tsum += values[i];
  }
  if (tsum < x)
    return -1;
  if (tsum == x)
    return n;
  sort(values.rbegin(), values.rend());
  tsum = 0;
  llint ans = 0;
  for (int i = 0; i < n; i++) {
    tsum += values[i];
    ans++;
    if (tsum >= x)
      return ans;
  }
  return ans;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  llint t;
  cin >> t;
  while (t--) {
    cout << __calc__() << endl;
  }

  return 0;
}
