#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <map>
#include <memory>
#include <numeric>
#include <optional>
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

std::optional<std::string> __winner__(const int a, const int b) {
  if (a > b)
    return "DRAGON";
  else if (b > a)
    return "SLOTH";
  return std::nullopt;
}

std::string __calc__() {
  llint a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;

  typedef std::optional<std::string> rettype;

  if (rettype winner = __winner__(a + b + c, d + e + f); winner.has_value())
    return winner.value();
  else {
    if (rettype winner = __winner__(a, d); winner.has_value())
      return winner.value();
    else if (rettype winner = __winner__(b, e); winner.has_value())
      return winner.value();
    return "TIE";
  }
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
