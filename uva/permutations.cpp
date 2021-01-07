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
// https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=882

typedef long long int llint;
typedef long double ldouble;

std::vector<llint> fval(21, 0);

void __update_fval__() {
  fval[0] = 1;
  for (llint i = 1; i < 21; i++)
    fval[i] = fval[i - 1] * (i);
  return;
}

void __calc__() {
  std::string chars;
  std::cin >> chars;

  llint perm;
  std::cin >> perm;
  std::sort(chars.begin(), chars.end());

  std::string answer = chars;
  std::vector<char> ava(chars.begin(), chars.end());
  int index = 0;

  while (index < chars.size() - 1) {
    int t = chars.size() - 1 - index;
    llint per_step = fval[chars.size() - 1 - index];
    llint char_ind = perm / per_step;
    perm -= per_step * char_ind;
    answer[index] = ava[char_ind];
    ava.erase(ava.begin() + char_ind);
    index++;
  }

  answer[answer.size() - 1] = ava[0];
  std::cout << answer << std::endl;
  return;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  __update_fval__();
  llint t;
  std::cin >> t;
  for (llint i = 0; i < t; i++) {
    __calc__();
  }
  return 0;
}
