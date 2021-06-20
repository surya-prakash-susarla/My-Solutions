#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <utility>
#include <vector>

#define in scanf
#define out printf

// Problem:

typedef long long int llint;
typedef long double ldouble;

std::vector<llint> __calc__() {
  llint n, x;
  std::cin >> n >> x;
  typedef std::pair<llint, llint> pint;
  std::vector<pint> values(n);
  llint temp;
  for (llint i = 0; i < n; i++) {
    std::cin >> temp;
    values[i] = {temp % n == 0 ? temp / x : temp / x + 1, i + 1};
  }

  std::sort(values.begin(), values.end(), [](const pint& a, const pint& b) {
    if (a.first < b.first)
      return true;
    else if (a.first == b.first)
      return a.second < b.second;
    return false;
  });

  std::vector<llint> answer;
  for (const pint& i : values)
    answer.push_back(i.second);

  return answer;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  llint t;
  std::cin >> t;

  for (llint i = 1; i <= t; i++) {
    const std::vector<llint> answer = __calc__();

    std::cout << "Case #" << i << ":";
    for (const llint& j : answer)
      std::cout << " " << j;

    std::cout << std::endl;
  }

  return 0;
}
