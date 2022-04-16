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

bool __calc__() {
  std::string value;
  cin >> value;

  if (value.size() == 1)
    return false;

  reverse(value.begin(), value.end());

  // cout << value[0] << endl;
  // cout << value[1] << endl;

  return std::any_of(value.begin() + 1, value.end(),
                     [](const char& c) { return c == '1'; });
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
