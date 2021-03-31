#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <map>
#include <memory>
#include <numeric>
#include <stack>
#include <utility>
#include <vector>


#define in scanf
#define out printf

// Problem:

typedef long long int llint;
typedef long double ldouble;

llint __calc__() {
  llint n, k;
  std::cin >> n >> k;
  std::string input;
  std::cin >> input;
  input = "-" + input;

  llint cs = 0;
  for (llint i = 1; i <= n / 2; i++)
    cs += input[i] != input[n - i + 1] ? 1 : 0;

  return std::abs(cs - k);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  llint t;
  std::cin >> t;
  for (llint i = 1; i <= t; i++) {
    llint answer = __calc__();
    std::cout << "Case #" << i << ": " << answer << "\n";
  }

  return 0;
}
