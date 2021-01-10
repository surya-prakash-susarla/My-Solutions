#include <algorithm>
#include <bitset>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

// Problem :
// https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=1662

typedef long long int llint;
typedef long double ldouble;

#define LOG std::cout

llint n, k, s;

std::vector<std::vector<llint>> memo;

llint __dprec__(const llint& cost, const llint& steps) {
  if (cost == 0 and steps == 0)
    return 1;
  else if (steps == 0 || cost < 0)
    return 0;

  // LOG << "calculating costs for : " << cost << " " << steps << std::endl;

  llint& mem = memo[cost][steps];
  // LOG << "current memo value : " << mem << std::endl;
  if (mem != -1)
    return mem;

  mem = 0;
  for (llint i = 1; i <= s; i++) {
    mem += __dprec__(cost - i, steps - 1);
  }
  // LOG << "returning mem value : " << mem << std::endl;
  return mem;
}

void __calc__() {
  std::string input;
  while (std::getline(std::cin, input)) {
    std::stringstream stream(input);
    stream >> n;
    stream >> k;
    stream >> s;
    // LOG << "values of n,k,s : " << n << " " << k << " " << s << std::endl;
    llint answer = 0;
    // __rec__(0, 0, answer);
    memo.clear();
    memo.resize(n + 1, std::vector<llint>(k + 1, -1));
    answer = __dprec__(n, k);
    std::cout << answer << std::endl;
  }
  return;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  __calc__();
  return 0;
}
