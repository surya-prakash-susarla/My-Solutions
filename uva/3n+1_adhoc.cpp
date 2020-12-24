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

typedef long long int llint;
typedef long double ldouble;

// Problem: https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=36

std::map<llint, llint> mem;

llint __calc__(llint input) {
  if (input == 1) return 1;
  llint& stored = mem[input];
  if (stored == 0) {
    if (input % 2 == 1)
      input = (3 * input + 1);
    else
      input /= 2;
    stored = __calc__(input) + 1;
  }
  return stored;
}

int main() {
  std::pair<llint, llint> input;
  while (in("%lld %lld", &input.first, &input.second) != EOF) {
    llint answer = 0;
    for (llint i = std::min(input.first, input.second);
         i <= std::max(input.first, input.second); i++)
      answer = std::max(answer, __calc__(i));
    out("%lld %lld %lld\n", input.first, input.second, answer);
  }

  return 0;
}
