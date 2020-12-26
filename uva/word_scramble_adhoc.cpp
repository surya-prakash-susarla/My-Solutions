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
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=424

typedef long long int llint;
typedef long double ldouble;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::string input;
  while (std::getline(std::cin, input)) {
    std::stack<char> temp;
    for (const char& c : input) {
      if (c == ' ') {
        while (!temp.empty()) {
          std::cout << temp.top();
          temp.pop();
        }
        std::cout << " ";
      } else {
        temp.push(c);
      }
    }
    while (!temp.empty()) {
      std::cout << temp.top();
      temp.pop();
    }
    std::cout << "\n";
  }
  return 0;
}
