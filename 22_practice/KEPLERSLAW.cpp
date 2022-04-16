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

// Problem:

typedef long long int llint;
typedef long double ldouble;

using namespace std;

bool __calc__() {
  llint t1, t2, r1, r2;
  cin >> t1 >> t2 >> r1 >> r2;
  return ((double)(t1 * t1) / (r1 * r1 * r1)) ==
         ((double)(t2 * t2) / (r2 * r2 * r2));
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  llint t;
  cin >> t;
  for (llint i = 0; i < t; i++) {
    cout << (__calc__() ? "Yes" : "No");
    if (i < t - 1)
      cout << endl;
  }

  return 0;
}
