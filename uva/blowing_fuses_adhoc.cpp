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

// Problem: https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=602

typedef long long int llint;
typedef long double ldouble;

std::pair<bool, int> __calc__(const int n, const int m, const int c) {
  if (n == 0 && m == 0 && c == 0) {
    return {false, -1};
  }
  std::vector<llint> caps(n);
  for (llint i = 0; i < n; i++) {
    std::cin >> caps[i];
  }
  // std::cout << "----value of caps : " << std::endl;
  // for ( llint i=0 ; i<caps.size() ; i++ )
  //   std::cout << caps[i] << " " ; 
  // std::cout << std::endl;
  std::vector<bool> us(n, false);
  bool failed = false;
  llint current_usage = 0, maxval = 0, temp;
  for (llint i = 0; i < m; i++) {
    std::cin >> temp;
    // std::cout << "value of m  : " << temp << std::endl;
    if ( failed ){
      continue;
    }
    temp -= 1;
    if (us[temp]) {
      // std::cout << "turning off dev : " << temp+1 << std::endl;
      current_usage -= caps[temp];
    } else {
      // std::cout << "turning on : " << temp+1 << std::endl;
      current_usage += caps[temp];
    }
    us[temp] = !us[temp];
    // std::cout << "Current usage : " << current_usage << std::endl;
    if (current_usage > c) {
      failed = true;
    } else {
      maxval = std::max(maxval, current_usage);
    }
  }
  if ( failed ){
    return {false, -1};
  }
  return {true, maxval};
}

int main() {
  std::ios_base::sync_with_stdio(false);
  llint n, m, c, t = 1;
  bool done = false;
  while (not done) {
    std::cin >> n >> m >> c;
    if (n == 0 && m == 0 && c == 0) {
      done = true;
      continue;
    }
    const std::pair<bool, llint>& answer = __calc__(n, m, c);
    std::cout << "Sequence " << t++ << "\nFuse was ";
    if (answer.first) {
      std::cout << "not blown.\nMaximal power consumption was "
                << answer.second << " amperes.\n";
    } else {
      std::cout << "blown.\n";
    }
    std::cout << "\n";
  }
  return 0;
}
