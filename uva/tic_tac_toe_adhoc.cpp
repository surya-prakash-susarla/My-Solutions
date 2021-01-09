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
#include <stack>
#include <utility>
#include <vector>

// Problem:
// https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=1304

typedef long long int llint;
typedef long double ldouble;

typedef std::pair<bool, bool> win;

#define LOG std::cout

inline void __update__(const char& c, win& value) {
  if (c == 'X')
    value.first = true;
  else if (c == 'O')
    value.second = true;
}

win __winner__(const std::vector<std::string> input, llint& x, llint& o) {
  x = 0;
  o = 0;
  for (const std::string& i : input)
    for (const char& c : i)
      if (c == 'X')
        x++;
      else if (c == 'O')
        o++;
  win answer({false, false});
  // check rows and cols
  for (llint i = 0; i < 3; i++) {
    if (input[i][0] == input[i][1] and input[i][1] == input[i][2]) {
      __update__(input[i][0], answer);
    }
    if (answer.first and answer.second)
      return answer;
  }
  for (llint i = 0; i < 3; i++) {
    if (input[0][i] == input[1][i] and input[1][i] == input[2][i]) {
      __update__(input[0][i], answer);
    }
    if (answer.first and answer.second)
      return answer;
  }
  // check diagonals
  if (input[0][0] == input[1][1] and input[1][1] == input[2][2])
    __update__(input[0][0], answer);
  if (input[0][2] == input[1][1] and input[1][1] == input[2][0])
    __update__(input[1][1], answer);
  return answer;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  llint t;
  std::cin >> t;
  llint orig = t;
  while (t-- > 0) {
    std::vector<std::string> input(3);
    for (llint i = 0; i < 3; i++)
      std::cin >> input[i];
    std::cin >> std::ws;
    // LOG << "input for case # " << orig - t << std::endl;
    // for ( const std::string& j : input ) std::cout << j << std::endl;
    llint x = 0, o = 0;
    win answer = __winner__(input, x, o);
    bool valid = false;
    // LOG << "x and o : " << x << " " << o << std::endl;
    // LOG << "answer values ; " << answer.first << " " << answer.second <<
    // std::endl;
    if (answer.first and answer.second)
      valid = false;
    else if (answer.first)
      valid = (x == o + 1);
    else if (answer.second)
      valid = (x == o);
    else
      valid = (x == o or x == o + 1);
    if (valid)
      std::cout << "yes\n";
    else
      std::cout << "no\n";
  }

  return 0;
}
