#include <algorithm>
#include <bitset>
#include <cmath>
#include <functional>
#include <iostream>
#include <limits>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <stack>
#include <utility>
#include <vector>

// Problem :
// https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=1082

typedef long long int llint;
typedef long double ldouble;

llint r = -1, p = -1, ind = 1;
std::string temp;

void __calc__() {
  std::cin >> r >> p;
  std::cin >> std::ws;
  if (r == 0 && p == 0)
    return;
  if (ind > 1)
    std::cout << "\n";
  // Actual names not useful anyway so just loop input.
  for (llint i = 0; i < r; i++) {
    std::getline(std::cin, temp);
    std::cin >> std::ws;
  }
  std::string answer_name;
  float answer_compl = 0.0;
  double answer_price = std::numeric_limits<double>::max();
  for (llint i = 0; i < p; i++) {
    std::string current_name;
    std::getline(std::cin, current_name);
    double price;
    std::cin >> price;
    llint sr;
    std::cin >> sr;
    std::cin >> std::ws;
    for (llint j = 0; j < sr and j < 10; j++) {
      std::getline(std::cin, temp);
      std::cin >> std::ws;
    }
    float compliance = sr / (float)r;
    if ((compliance > answer_compl) or
        (compliance == answer_compl and price < answer_price)) {
      answer_name = current_name;
      answer_compl = compliance;
      answer_price = price;
    }
  }
  std::cout << "RFP #" << ind++ << "\n";
  std::cout << answer_name << "\n";
  __calc__();
}

int main() {
  std::ios_base::sync_with_stdio(false);
  __calc__();
  return 0;
}
