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

// Problem:
// https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=208

int main() {
  std::ios_base::sync_with_stdio(false);
  std::string input;
  bool left = true;
  while (std::getline(std::cin, input)) {
    // std::cout << "LINE:" << input << "\n";
    for (const char c : input) {
      if (c == '\"') {
        if (left)
          std::cout << "``";
        else
          std::cout << "''";
        left = not left;
      } else {
        std::cout << c;
      }
    }
    std::cout << "\n";
  }
  return 0;
}
