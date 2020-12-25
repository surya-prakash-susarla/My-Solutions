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

// Problem: https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=514

typedef long long int llint;
typedef long double ldouble;

float h, u, d, f, fd;

std::pair<bool, llint> __calc__() {
  fd = (u * f) / 100.0;
  bool climbed = false;
  int days = 0;
  float current_h = 0;
  while (true) {
    days += 1;
    if (days > 1) {
      u -= fd;
    }
    if (u > 0) {
      current_h += u;
    }
    if (current_h > h) {
      climbed = true;
      break;
    }
    current_h -= d;
    // std::cout << "End of day : " << days << std::endl;
    // std::cout << "u: " << u << " d: " << d << std::endl;
    // std::cout << "fd: " << fd << std::endl;
    // std::cout << "Current height : " << current_h << std::endl;
    if (current_h < 0) {
      // std::cout << "failure , u: " << u << " d: " << d << std::endl;
      break;
    }
  }
  return {climbed, days};
}

int main() {
  std::ios_base::sync_with_stdio(false);
  while (1) {
    std::cin >> h >> u >> d >> f;
    if (h == 0) {
      break;
    } else {
      const std::pair<bool, llint>& answer = __calc__();
      std::string at = answer.first ? "success on day " : "failure on day ";
      at += std::to_string(answer.second);
      std::cout << at << "\n";
    }
  }
  return 0;
}
