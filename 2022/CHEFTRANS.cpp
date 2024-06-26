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

std::string __calc__() {
  llint x, y, z;
  cin >> x >> y >> z;
  if (x + y == z)
    return "EQUAL";
  else if (x + y < z)
    return "PLANEBUS";
  return "TRAIN";
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  llint t;
  cin >> t;
  for (llint i = 0; i < t; i++) {
    cout << __calc__();
    if (i < t - 1)
      cout << endl;
  }

  return 0;
}
